#include "../header.h"

#define m int(1e4 + 3)
#define ll long long

// Top Down Approach
int nWays(ll n, vector<int>& dp) {
    if (n <= 2) {
        return n;
    }
    if (dp[n] == -1) {
        dp[n] = (nWays(n - 1, dp) + (n - 1) * nWays(n - 2, dp)) % m;
    }
    return dp[n];
}

// Bottom Up Approach
int nWays(ll n) {
    if (n <= 2) {
        return n;
    }

    ll a = 1, b = 2, sum;
    for (int i = 3; i <= n; i++) {
        sum = (b + (i - 1) * a) % m;
        a = b;
        b = sum;
    }

    return b;
}


int Solution::solve(int A) {
    // Top Down Approach
    // vector<int> dp(A + 1, -1);
    // return nWays(A, dp);

    // Bottom Up Approach
    return nWays(A);
}