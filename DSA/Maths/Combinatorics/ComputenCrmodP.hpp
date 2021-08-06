#include "../../header.h"

int fastPower(long long A, int p, int m) {
    long long ans = 1;
    while (p > 0) {
        if (p & 1){
            ans = (ans * A) % m;
        }
        A = (A * A) % m;
        p >>= 1;
    }

    return static_cast<int>(ans);
}

int solve(int A, int B, int C) {
    using ll = long long;
    ll Nr = 1;
    for (int i = 0; i < B; i++) {
        Nr = (Nr * A) % C;
        A--;
    }
    
    ll BFac = 1;
    for (int i = 2; i <= B; i++) {
        BFac = (BFac * i) % C;
    }

    ll DrInv = fastPower(BFac, C - 2, C);

    return (Nr * DrInv) % C;
}