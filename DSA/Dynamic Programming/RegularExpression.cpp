#include "../header.h"

int isMatch(const string A, const string B) {
    int i, j;
    const int nA = A.size();
    const int nB = B.size();
    vector<vector<bool>> dp(nA + 1, vector<bool>(nB + 1));
    
    // filling initial values for dp matrix
    dp[0][0] = true;
    for (i = 1; i <= nA; i++) {
        dp[i][0] = false;
    }
    dp[0][1] = (B.front() == '*');
    for (i = 1; i <= nB; i++) {
        dp[0][i] = false;
    }
    
    for (i = 1; i <= nA; i++) {
        for (j = 1; j <= nB; j++) {
            if (A[i - 1] == B[j - 1] || // if chars match or patten char is ?
                B[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (B[j - 1] == '*') { 
                    /* if '*' try to proceed both A & B
                    as well as 
                    proceed just A and check(as '*' can match more than 1 char in A) */
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else { // if they 
                    dp[i][j] = false;
                }
            }
        }
    }
    
    return dp[nA][nB];
}