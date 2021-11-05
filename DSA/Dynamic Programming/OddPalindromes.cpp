#include "../header.h"

#define m int(1e9 + 7)

int findOddPalindromes(const string& A, int i, int j, vector<vector<int>>& dp) {
    int nA = A.size();
    if (i < 0 || j >= nA) {
        return 1;
    }
    if (i == 0 && j == nA - 1) {
        return (A[i] == A[j]) ? 2 : 1;
    }

    if (dp[i][j] == 0) {
        dp[i][j] = (findOddPalindromes(A, i - 1, j, dp) + 
            findOddPalindromes(A, i, j + 1, dp)) % m;
        if (A[i] != A[j]) {
            dp[i][j] = (dp[i][j] - findOddPalindromes(A, i - 1, j + 1, dp) + m) % m;
        }
    }

    return dp[i][j];
}

vector<int> solve(string A) {
    const int nA = A.size();
    vector<int> ans(nA);
    vector<vector<int>> dp(nA, vector<int>(nA));
    
    for (int i = 0; i < nA; i++) {
        if (i == 0 || i == nA - 1) {
            ans[i] = 1;
        } else {
            ans[i] = findOddPalindromes(A, i - 1, i + 1, dp);
        }
    }

    return ans;
}