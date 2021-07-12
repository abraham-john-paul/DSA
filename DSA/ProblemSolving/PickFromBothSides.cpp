#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solve(vector<int> &A, int B) {
    int curMax = 0;
    for (int i = 0; i < B; i++) {
        curMax += A[i];
    }
    int ans = curMax;
    int end = A.size() - 1;
    int n = B - 1;
    while (n >= 0) {
        curMax -= A[n--];
        curMax += A[end--];
        if (ans < curMax) {
            ans = curMax;
        }
    }

    return ans;
}

int main() {
    vector<int> A = {1, 2};
    int B = 1;
    cout << solve(A, B);
    return 0;
}