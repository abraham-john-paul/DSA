#include "../header.h"

int ways(const string& A, int i,
    const string& B, int j,
    vector<vector<int>>& dp) {
        if (j == 0) {
            return 1;
        }
        if (i == 0) {
            return 0;
        }
        if (dp[i][j] == -1) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = ways(A, i - 1, B, j - 1, dp) +
                    ways(A, i - 1, B, j, dp);
            } else {
                dp[i][j] = ways(A, i - 1, B, j, dp);
            }
        }
        return dp[i][j];
    }

int numDistinct(string A, string B) {
    const int nA = A.size();
    const int nB = B.size();
    vector<vector<int>> dp(nA + 1, vector<int>(nB + 1, -1));
    return ways(A, nA, B, nB, dp);
}
