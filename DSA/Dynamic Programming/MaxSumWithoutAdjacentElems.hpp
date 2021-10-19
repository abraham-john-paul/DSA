#include "../header.h"
// Top Down Approach
int maxSum(const vector<vector<int>> &A, vector<int>& dp, int idx) {
    if (idx < 0) {
        return 0; 
    }
    int iMax = max(A[0][idx - 1], A[1][idx - 1]);
    if (dp[idx] == INT_MIN) {
        dp[idx] = max(iMax + maxSum(A, dp, idx - 2), 
            max(maxSum(A, dp, idx - 1), maxSum(A, dp, idx - 2)));
    }
    return dp[idx];
}

int Solution::adjacent(vector<vector<int> > &A) {
    // Bottom Up Approach
    int included = 0;
    int excluded = 0;
    int prevIncluded;
    int iMax;
    const int nA = A[0].size();
    for (int i = 0; i < nA; i++) {
        iMax = max(A[0][i], A[1][i]);
        prevIncluded = included;
        included = excluded + iMax;
        excluded = max(excluded, prevIncluded);
    }
    
    return max(included, excluded);

    // // Top Down Approach
    // int col = A[0].size();
    // vector<int> dp(col + 1, INT_MIN);
    // return maxSum(A, dp, col);
}