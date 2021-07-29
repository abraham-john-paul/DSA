#include "../header.h"
#include "../commonOps.hpp"

int solve(vector<int> &A, int B) {
    const int n = A.size();
    vector<ll> v(B);
    for (int i = 0; i < n; i++) {
        v[A[i] % B]++;
    }

    const int m = 1000000007;
    long long ans = v[0] * (v[0] - 1) / 2;
    int i = 1;
    int j = B - 1;
    while (i <= j) {
    if (i == j) {
        ans = (ans + v[i] * (v[j] - 1) / 2) % m;
    } else {
        ans = (ans + v[i] * v[j]) % m;
    }
        i++;
        j--;
    }
    return ans;
}