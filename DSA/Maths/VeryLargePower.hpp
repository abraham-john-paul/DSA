#include "../header.h"

int fastPower(ll a, int p, int m) {
    ll ans = 1;

    while (p > 0) {
        if (p & 1) {
            ans = (ans * a) % m;
            p--;
        }
        a = (a * a) % m;
        p >>= 1;
    }
    return ans;
}

long long factorial(int A) {
    int ans = 1;
    int m = 1000000007;
    for (int i = 1; i <= A; i++) {
        ans  = (ans * i) % (m - 1);
    }
    return ans;
}

int solve(int A, int B) {
    using ll = long long;
    const int m = 1000000007;
    ll bFac = factorial(B);
    ll r = bFac % (m - 1);
    return fastPower(A, r, m);
}