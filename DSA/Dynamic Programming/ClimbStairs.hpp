#include "../header.h"

int helper(int n, vector<int>& dp) {
    if (n <= 2) {
        return n;
    }
    if (dp[n] == -1) {
        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

    return dp[n];
}


int Solution::climbStairs(int A) {
    // Top Down Approach
    // vector<int> dp(A + 1, -1);
    // return helper(A, dp);

    // Bottom Up approach
    if (A <= 2) {
        return A;
    }

    int prev = 1, cur = 2;
    int sum;
    for (int i = 3; i <= A; i++) {
        sum = prev + cur;
        prev = cur;
        cur = sum;
    }  

    return cur;
}