#include "../header.h"

int fastPower(long long a, int p, int m) {
    long long ans = 1;
    
    while (p) {
        if (p & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        p >>= 1;
    }
    
    return ans;
}

int solve(vector<int> &A) {
    const int m = 1000000007;
    long long ans = 0;
    const int nA = A.size();
    
    sort(A.begin(), A.end());
    long long j;
    for (int i = 0; i < nA; i++) {
        j = fastPower(2, nA - i - 1, m);
        ans = (ans - (A[i] * j) % m + m) % m;
        j = fastPower(2, i, m);
        ans = (ans + (A[i] * j) % m + m) % m;
    }
    
    return ans;
}