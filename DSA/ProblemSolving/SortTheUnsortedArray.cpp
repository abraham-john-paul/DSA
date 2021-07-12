#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <utility>

using namespace std;

int solve(vector<int>& A) {
    const int n = A.size();
    int start = 0;
    int end = n - 1;
    
    while(start < n - 1) {
        if (A[start] > A[start + 1]) {
            break;
        }
        start++;
    }

    if (start == n - 1) {
        return 0;
    }

    while (end > 0) {
        if (A[end] < A[end - 1]) {
            break;
        }
        end--;
    }

    auto p = minmax_element(A.begin() + start, A.begin() + end + 1);
    int mn = *(p.first);
    int mx = *(p.second);
    
    int i = 0;
    while (i < start) {
        if (A[i] > mn) {
            start = i;
            break;
        }
        i++;
    }

    i = n - 1;
    while (i > end) {
        if (A[i] < mx) {
            end = i;
            break;
        }
        i--;
    }

    return end - start + 1;
}

int main() {
    vector<int> A = {-146316343, 179840175, 760528516};
    cout << solve(A);
    return 0;
}