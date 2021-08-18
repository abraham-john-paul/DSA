#include "../header.h"

int solve(vector<int>& A) {
    int ans = 0;

    sort(A.begin(), A.end());
    int prev = A[0];
    const int nA = A.size();
    for (int i = 1; i < nA; i++) {
        if (A[i] <= prev) {
            ans += ((prev + 1) - A[i]);
        }
        prev = A[i];
    }

    return ans;
}