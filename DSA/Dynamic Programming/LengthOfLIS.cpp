#include "../header.h"

int lis(const vector<int> &A) {
    int ans = 0;
    const int nA = A.size();
    vector<int> dp(nA + 1);
    int i, j;
    for (i = 1; i <= nA; i++) {
        for (j = 1; j < i; j++) {
            if (A[j - 1] < A[i - 1]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
        ans = max(ans, dp[i]);
    }
    
    return ans;
}
