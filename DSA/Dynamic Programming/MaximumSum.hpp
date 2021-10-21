#include "../header.h"

int Solution::solve(vector<int> &A, int B, int C, int D) {
    const int nA = A.size();
    vector<vector<int>> dp(3, vector<int>(nA + 1, INT_MIN));
    
    for(int i = 1; i <= nA; i ++) {
        dp[0][i] = max(dp[0][i - 1], B * A[i - 1]);
        dp[1][i] = max(dp[1][i - 1], C * A[i - 1] + dp[0][i]);
        dp[2][i] = max(dp[2][i - 1], D * A[i - 1] + dp[1][i]);
    }
    
    return dp[2][nA];
}
