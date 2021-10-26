#include "../header.h"

int findAnyTwoMatch(const string& A, const string& B, vector<vector<int>>& dp, int i, int j, bool& ans) {
    if (i == 0 || j == 0 || ans) {
        return 0;
    }
    if (i == j) {
        return findAnyTwoMatch(A, B, dp, i - 1, j, ans);
    }
    if (dp[i][j] == 0) {
        if (A[i - 1] == A[j - 1]) {
            dp[i][j] = 1 + findAnyTwoMatch(A, B, dp, i - 1, j - 1, ans);
        } else {
            dp[i][j] = max(findAnyTwoMatch(A, B, dp, i - 1, j, ans), 
                findAnyTwoMatch(A, B, dp, i, j - 1, ans));
        }
        if (dp[i][j] >= 2) {
            ans = true;
        }
    }
    return dp[i][j];
}

int anytwo(string A) {
    const int nA = A.size();
    vector<vector<int>> dp(nA + 1, vector<int>(nA + 1));
    bool ans = false;
    findAnyTwoMatch(A, A, dp, nA, nA, ans);
    return ans;
}
