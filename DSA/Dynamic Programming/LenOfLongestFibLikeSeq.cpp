#include "../header.h"

int solve(vector<int> &A) {
    unordered_map<int, int> idxMap;
    const int nA = A.size();
    int i, j;
    for (i = 0; i < nA; i++) {
        idxMap[A[i]] = i;
    }

    vector<vector<int>> dp(nA, vector<int>(nA));
    int ans = 0;
    int a;
    for (i = 1; i < nA; i++) {
        for (j = i - 1; j >= 0; j--) {
            a = A[i] - A[j];
            if (idxMap.find(a) != idxMap.end() && idxMap[a] < j) {
                dp[i][j] += (dp[j][idxMap[a]] + 1);
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 2;
            }
        }
    }

    return ans;
}
