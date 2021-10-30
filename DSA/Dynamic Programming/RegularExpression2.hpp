#include "../header.h"

enum class Match {
    True,
    False,
    NA
};

Match match(const string& A, const string& B, int i, int j, vector<vector<Match>>& dp) {
    if (i == 0) {
        return Match::True;
    }
    if (j == 0) {
        return Match::False;
    }
    if (dp[i][j] == Match::NA) {
        if (A[i - 1] == B[j - 1] || B[j - 1] == '.') {
            dp[i][j] = match(A, B, i - 1, j - 1, dp);
        } else {
            if (B[j - 1] == '*') {
                if (B[j - 2] == A[i - 1] || B[j - 2] == '.') {
                    dp[i][j] = match(A, B, i - 1, j, dp);
                } else {
                    dp[i][j] = match(A, B, i, j - 2, dp);
                }
            } else {
                dp[i][j] = Match::False;
            }
        }
    }
    return dp[i][j];
}

int isMatch(const string A, const string B) {
    const int nA = A.size();
    const int nB = B.size();
    vector<vector<Match>> dp(nA + 1, vector<Match>(nB + 1, Match::NA));
    return match(A, B, nA, nB, dp) == Match::True ? 1 : 0;
}

// int Solution::isMatch(const string A,
//     const string B) {
//     int la = A.length();
//     int lb = B.length();
//     vector < vector < int > > dp(la + 1, vector < int > (lb + 1, 0));
//     for (int i = 0; i < la + 1; i++) {
//         for (int j = 0; j < lb + 1; j++) {
//             if (i == 0 && j == 0) {
//                 dp[i][j] = 1;
//             } else if (j == 0) {
//                 dp[i][j] = 0;
//             } else if (i == 0) {
//                 if (B[j - 1] == '*') {
//                     dp[i][j] = dp[i][j - 2];
//                 }
//             } else {
//                 if (A[i - 1] == B[j - 1] || B[j - 1] == '.') {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } else if (B[j - 1] == '*') {
//                     dp[i][j] = dp[i][j - 2];
//                     if (A[i - 1] == B[j - 2] || B[j - 2] == '.') {
//                         dp[i][j] = dp[i][j] || dp[i - 1][j];
//                     }
//                 } else {
//                     dp[i][j] = 0;
//                 }
//             }
//         }
//     }
//     return dp[la][lb];
// }