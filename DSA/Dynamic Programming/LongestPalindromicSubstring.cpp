#include "../header.h"

string solve(string A) {
    const int nA = A.size();
    vector<vector<bool>> dp(nA, vector<bool>(nA, false));
    for (int i = 0; i < nA; i++) {
        dp[i][i] = true;
    } 
    int i, j;
    int ans = 1;
    int start = 0;
    for (int l = 2; l <= nA; l++) {
        i = 0;
        j = i + l - 1;
        while (j < nA) {
            if (A[i] == A[j]) {
                dp[i][j] = (j == i + 1) || dp[i + 1][j - 1];
                if (dp[i][j]) {
                    if (ans < j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    } else if (ans == j - i + 1) {
                        start = min(start, i);
                    }
                }
            } else {
                dp[i][j] = false;
            }
            i++;
            j++;
        }
    }

    return A.substr(start, ans);
}


// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int nS = s.size();
//         vector<vector<bool>> dp(nS, vector<bool>(nS, false));
//         int i, j;
//         int start = 0;
//         int ans = 1;
//         for (i = 0; i < nS; i++) {
//                 dp[i][i] = true;
//         }
        
//         for (int l = 2; l <= nS; l++) {
//             i = 0;
//             j = i + l - 1;
//             while (j < nS) {
//                 if (s[i] == s[j]) {
//                     dp[i][j] = ((j == i + 1) || dp[i + 1][j - 1]);
//                 } else {
//                     dp[i][j] = false;
//                 }
//                 if (dp[i][j] == true) {
//                     start = i;
//                     ans = j - i + 1;
//                 }
//                 i++;
//                 j++;
//             }
//         }
        
//         return s.substr(start, ans);
//     }
};