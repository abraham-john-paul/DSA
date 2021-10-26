#include "../header.h"

#define m int(1e6 + 7)

int coinchange2(vector<int> &A, int B) {
    vector<int> dp(B + 1, 0);
    dp[0] = 1;
    const int nA = A.size();
    int i;
    for (int e : A) {
        for (i = 1; i <= B; i++) {
            if (i - e >= 0) {
                dp[i] = (dp[i] + dp[i - e]) % m;
            }
        }
    }
    return dp[B];
}