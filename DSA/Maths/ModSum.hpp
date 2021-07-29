#include "../header.h"
#include "../commonOps.hpp"
int solve(vector<int> &A) {
    using ll = long long;
    ll ans = 0;
    const int m = 1000000007;
    const int n = A.size();
    
    sort(A.begin(), A.end());
    vector<int> prefixSum(n + 1);
    partial_sum(
        A.begin(), A.end(), 
        prefixSum.begin() + 1, 
        [m](int a, int b) { return (a + b); }
    );
    int i = 0;
    while (i < n) {
        int j = upper_bound(A.begin() + i, A.end(), A[i]) - A.begin();
        ans = (ans  + prefixSum[i] % A[i] * (j - i)) % m;
        ans = (ans + ((prefixSum.back() - prefixSum[j]) % A[i] * (j - i)) ) % m;
        i = j;
    }

    return (int)ans;
}