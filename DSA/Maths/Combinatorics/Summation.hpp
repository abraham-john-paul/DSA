#include "../../header.h"

int fastPower(long long a, int p, int m) {
    long long ans = 1;

    while (p > 0) {
        if (p & 1) {
            ans = (ans * a) % m;
        }
        p >>= 1;
        a = (a * a) % m;
    }

    return ans;
}

int solve(int A) {
    // simplify the expression as A(A - 1)*3^(A-2) using 
    // binomial expansion and taking out terms from nCr
    const int m = 1000000007;
    long long ans = 1;
    ans = (ans * A) % m;
    ans = (ans * (A - 1)) % m;
    ans = (ans * fastPower(3, A - 2, m)) % m;

    return ans;
}