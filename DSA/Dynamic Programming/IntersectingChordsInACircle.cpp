#include "../header.h"

#define m int(1e9 + 7)

int chordCnt(int A) {
    vector<int> dp(A + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= A; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % m + m) % m;
        }
    }
    return dp[A];
}