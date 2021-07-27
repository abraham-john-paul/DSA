#include <bits/stdc++.h>
using namespace std;
#include "commonOps.hpp"
using ll = long long;

int findSum(
    const vector<vector<int> > &A,
    const vector<vector<ll> > &prefixSum,
    int tLR, int tLC, 
    int bRR, int bRC) {
        const int m = 1000000007;
        ll ans = 0;
        ans = (ans + prefixSum[bRR][bRC] + m) % m;
        ans = (ans - prefixSum[bRR][tLC - 1] + m) % m;
        ans = (ans - prefixSum[tLR - 1][bRC] + m) % m;
        ans = (ans + prefixSum[tLR - 1][tLC - 1] + m) % m;
        return static_cast<int>(ans);
}

vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    const int r = A.size() + 1;
    if (r == 1) {
        return {};
    }
    const int c = A[0].size() + 1;
    const int m = 1000000007;
    
    // Creating Prefix Sum Matrix
    // Row wise prefix sum
    vector<vector<ll>> prefixSum(r, vector<ll>(c));
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            prefixSum[i][j] = (A[i - 1][j - 1] + prefixSum[i][j - 1] + m) % m;
        }
    }
    // Column wise prefix sum
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            prefixSum[i][j] = (prefixSum[i][j] + prefixSum[i - 1][j] + m) % m;
        }
    }

    const int q = B.size();
    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        ans[i] = findSum(A, prefixSum,
                        B[i], C[i],
                        D[i], E[i]);
    }

    return ans;
}