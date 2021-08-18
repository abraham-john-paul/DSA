#include "../header.h"

int solve(vector<int> &A) {
    int ans = 0;
    const int nA = A.size();
    for (int i = 0; i < nA; i++) {
        while (i != A[i]) {
            ans++;
            swap(A[i], A[A[i]]);
        }
    }
    return ans;
}