#include "../../header.h"

int solve(const vector<int>& A) {
    const int m = 1000000007;
    using ll = long long;
    ll ans = 0;
    const int n = A.size();
    ll nOnes;
    
    for (int i = 0; i < 32; i++) {
        nOnes = 0;
        for (const int e : A) {
            if (e & (1 << i)) {
                nOnes++;
            }
        }
        ans = (ans + (nOnes * (n - nOnes)) % m) % m;
    }

    return (ans << 1) % m;
}