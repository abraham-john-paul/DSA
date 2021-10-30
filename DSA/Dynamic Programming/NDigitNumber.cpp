#include "../header.h"

#define m 1000000007

int ways(int N, int sum, vector<vector<int>>& dp) {
    if (N == 1) {
        if (sum >= 1 && sum <= 9) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[N][sum] == -1) {
        dp[N][sum] = 0;
        for (int i = 0; i <= 9; i++) {
            if (sum >= i) {
                dp[N][sum] = (dp[N][sum] + ways(N - 1, sum - i, dp)) % m;
            } else {
                break;
            }
        }
    }

    return dp[N][sum];
}

int solve(int A, int B) {
    // TODO : Bottom Up
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, -1));
    return  ways(A, B, dp);
}