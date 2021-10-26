#include "../header.h"

int editDistance(const string& A, const string& B, vector<vector<int>>& dp,
    int i, int j) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (dp[i][j] == INT_MAX) {
            if (A[i - 1] != B[j - 1]) {
                dp[i][j] = 1 + min(editDistance(A, B, dp, i - 1, j - 1), 
                    min(editDistance(A, B, dp, i - 1, j), 
                        editDistance(A, B, dp, i, j - 1)));
            } else {
                dp[i][j] = editDistance(A, B, dp, i - 1, j - 1);
            }
        }
        return dp[i][j];
    }
    
int minDistance(string A, string B) {
    const int nA = A.size();
    const int nB = B.size();
    vector<vector<int>> dp(nA + 1, vector<int>(nB + 1, INT_MAX));

    return editDistance(A, B, dp, nA, nB);
}
