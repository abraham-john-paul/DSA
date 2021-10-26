#include "../header.h"

int lps(const string& A, vector<vector<int>>& dp, int& ans, int i, int j) {
    if (i == j) {
        return 1;
    }
    
    if (j < i) {
        return 0;
    }

    if (dp[i][j] == 0) {
        if (A[i - 1] == A[j - 1]) {
            dp[i][j] = 2 + lps(A, dp, ans, i + 1, j - 1);
        } else {
            dp[i][j] = max(lps(A, dp, ans, i + 1, j), 
                lps(A, dp, ans, i, j - 1));
        }
        ans = max(ans, dp[i][j]);
    }

    return dp[i][j];
}

int solve(string A) {
    const int nA = A.size();
    vector<vector<int>> dp(nA + 1, vector<int>(nA + 1));
    int ans = 0;
    lps(A, dp, ans, 1, nA);
    return ans;
}