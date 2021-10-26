#include "../header.h"

int findMinKnightHP(const vector<vector<int>>& A, vector<vector<int>>& dp, int i, int j) {
    if (i == A.size() || j == A[0].size()) {
        return dp[i][j];
    }
    int minHP;
    if (dp[i][j] == INT_MAX) {
        minHP = min(findMinKnightHP(A, dp, i + 1, j), 
            findMinKnightHP(A, dp, i, j + 1)) - A[i][j];
        dp[i][j] = max(1, minHP);
    }
    return dp[i][j];
}

int calculateMinimumHP(vector<vector<int> > &A) {
    const int nRow = A.size();
    const int nCol = A[0].size();
    vector<vector<int>> dp(nRow + 1, vector<int>(nCol + 1, INT_MAX));
    dp[nRow][nCol - 1] = 1;
    dp[nRow - 1][nCol] = 1;
    findMinKnightHP(A, dp, 0, 0);
    return dp[0][0];
}
