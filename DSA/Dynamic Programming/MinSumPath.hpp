#include "../header.h"

int findMinSumPath(const vector<vector<int>>& A, vector<vector<int>>& dp, int i, int j) {
    if (i == 0 || j == 0) {
        return INT_MAX;
    }
    if (dp[i][j] == 0) {
        int minSum = min(findMinSumPath(A, dp, i, j - 1), 
            findMinSumPath(A, dp, i - 1, j));
        dp[i][j] = (minSum == INT_MAX) ? 0 : minSum;
        dp[i][j] += A[i - 1][j - 1];
    }
    return dp[i][j];
}

int minPathSum(vector<vector<int> > &A) {
    int nRow = A.size();
    int nCol = A[0].size();
    vector<vector<int>> dp(nRow + 1, vector<int>(nCol + 1, INT_MAX));
    // return findMinSumPath(A, dp, nRow, nCol);
    int i, j;
    int minSum;
    for (i = 1; i <= nRow; i++) {
        for (int j = 1; j <= nCol; j++) {
            minSum = min(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = (minSum == INT_MAX) ? 0 : minSum;
            dp[i][j] += A[i - 1][j - 1];
        }
    }
    return dp[nRow][nCol];
}