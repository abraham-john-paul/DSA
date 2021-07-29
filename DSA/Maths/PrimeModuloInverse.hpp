#include "../header.h"
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

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

    // a %= m;
    // if (p == 0) {
    //     return 1;
    // }
    // if (p & 1) {
    //     return (a * fastPower((a * a) % m, p >> 1, m)) % m;
    // } else {
    //     return fastPower((a * a) % m, p >> 1, m);
    // }
}

int solve(int A, int B) {
    if (findGCD(A, B) == 1) {
        return fastPower(A, B - 2, B);
    } else {
        return -1;
    }
}
