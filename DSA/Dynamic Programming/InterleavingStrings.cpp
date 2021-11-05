#include "../header.h"
namespace Solution {
int isInterleave(string A, string B, string C);
}
int Solution::isInterleave(string A, string B, string C) {
    int nA = A.size();
    int nB = B.size();
    int nC = C.size();
    if (nA + nB != nC) {
        return false;
    }
    int i, j;
    vector<vector<bool>> dp(nA + 1, vector<bool>(nB + 1, false));
    char a, b, c;
    for (i = 0; i <= nA; i++) {
        a = A[i - 1];
        for (j = 0; j <= nB; j++) {
            b = B[j - 1];
            c = C[i + j - 1];
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                if (b == c) {
                    dp[i][j] = dp[i][j - 1];
                }
                continue;
            }else if (j == 0) {
                if (a == c) {
                    dp[i][j] = dp[i - 1][j];
                }
                continue;
            } else {
                if (a == c) {
                    dp[i][j] = dp[i - 1][j];
                }    
                if (b == c) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        } 
    }

    return dp[nA][nB];
}
