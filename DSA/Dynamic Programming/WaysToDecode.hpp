#include "../header.h"

#define m int(1e9 + 7)

int decode(const string& A, int idx, vector<int>& dp) {
    int nA = A.size();
    if (idx == nA) {
        return 1;
    }
    if (A[idx] == '0') {
        return 0;
    }
    if (dp[idx] == 0) {
        string sNum;
        sNum += A[idx];
        if (idx + 1 < nA) {
            sNum += A[idx + 1];
        }
        int num = stoi(sNum);
        if (num >= 10 && num <= 26) {
            dp[idx] = (decode(A, idx + 1, dp) + decode(A, idx + 2, dp)) % m;
        } else {
            dp[idx] = decode(A, idx + 1, dp);
        }
    }
    return dp[idx] % m;
}

int numDecodings(string A) {
    int n = A.size();
    vector<int> dp(n);
    return decode(A, 0, dp);
}