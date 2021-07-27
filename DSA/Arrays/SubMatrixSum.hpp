#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A) {
    using ll = long long;
    ll ans = 0;

    const ll n = A.size();
    if (n == 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += A[i][j] * (i + 1) * (j + 1) * (n - i) * (n - j);
        }
    }

    return static_cast<int>(ans);
}