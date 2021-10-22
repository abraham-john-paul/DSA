#include "../header.h"

int lcs(const string& A, const string& B, vector<vector<int>>& dp,
    int i, int j, int& ans) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j] == 0) {
        if (A[i - 1] == B[j - 1]) {
            dp[i][j] = lcs(A, B, dp, i - 1, j - 1, ans) + 1;
        } else {
            dp[i][j] = max(lcs(A, B, dp, i - 1, j, ans),
                lcs(A, B, dp, i, j - 1, ans));
        }
    }
    ans = max(ans, dp[i][j]);
    return dp[i][j];
}

int solve(string A, string B) {
    const int nA = A.size();
    const int nB = B.size();
    vector<vector<int>> dp(nA + 1, vector<int>(nB + 1));
    int i, j;
    int ans = INT_MIN;
    for (i = 1; i <= nA; i++) {
        for (j = 1; j <= nB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}