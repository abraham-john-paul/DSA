#include "../header.h"

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    const int nRow = A.size();
    const int nCol = A[0].size();
    vector<vector<int>> dp(nRow + 1, vector<int>(nCol + 1));
    int i, j;
    if (A[0][0] == 0) {
        dp[1][1] = 1;
    }
    for (i = 1; i <= nRow; i++) {
        for (j = 1; j <= nCol; j++) {
            if (A[i - 1][j - 1] == 0) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[nRow][nCol];
}