#include "../header.h"

// Bottom Up Approach
int nWays(int n, vector<int>& dp) {
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 2; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1); 
        }
    }

    return dp[n];
}

// // Top Down Approach
// int nWays(int n, vector<int>& dp) {
//     if (n == 0) {
//         return 0;
//     }
//     if (dp[n] == INT_MAX) {
//         for (int i = 1; i * i <= n; i++) {
//             dp[n] = min(dp[n], nWays(n - (i * i), dp) + 1);
//         }
//     }

//     return dp[n];
// }

int Solution::countMinSquares(int A) {
    // Bottom Up Approach
    vector<int> dp(A + 1);
    return nWays(A, dp);

    // // Top Down Approach
    // vector<int> dp(A + 1, INT_MAX);
    // retur nnWays(A, dp);
}
