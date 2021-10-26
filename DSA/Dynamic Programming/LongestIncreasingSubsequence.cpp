#include "../header.h"

// Top Down Approach
int LIS(const vector<int>& A, int idx, vector<int>& dp, int& ans) {
    if (idx == 0) {
        return 0;
    }
    if (dp[idx] == 0) {
        for (int i = 1; i < idx; i++) {
            if (A[i - 1] < A[idx - 1]) {
                dp[idx] = max(dp[idx], LIS(A, i, dp, ans));
            } else {
                LIS(A, i, dp, ans);
            }
        }
        dp[idx] += 1;
    }
    ans = max(ans, dp[idx]);
    return dp[idx];
}

int findLIS(vector<int> &A) {
    const int nA = A.size();
    vector<int> dp(nA + 1);
    int ans = 0;
    // LIS(A, nA, dp, ans);
    int i, j;
    for (i = 1; i <= nA; i++) {
        for (j = 1; j < i; j++) {
            if (A[i - 1] > A[j - 1])
            dp[i] = max(dp[i], dp[j]);
        } 
        dp[i] += 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}