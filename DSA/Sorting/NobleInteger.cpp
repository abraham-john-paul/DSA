#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findNoble(vector<int> &A) {
    sort(A.begin(), A.end());
    int p = 0;
    const int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        if(A[i] == A[i + 1]) {
            continue;
        } else {
            if (A[i] == n - i - 1) {
                return 1;
            } else  if (A[i] > n - i - 1) {
                break;
            }
        }
    }
    return (A.back() == 0) ? 1 : -1;
}

int main() {
    vector<int> v = {-4, -2, 0, -1, -6 };
    cout << findNoble(v);
    return 0;
}