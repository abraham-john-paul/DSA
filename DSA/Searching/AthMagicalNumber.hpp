#include "../header.h"

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);    
}

int solve(int A, int B, int C) {
    const int m = 1000000007;
    ll start = min(B, C);
    ll end = (ll)A * (ll)min(B, C);
    ll mid;
    ll cnt;
    ll _lcm = lcm(B, C);
    while (start <= end) {
        mid = start + (end - start) / 2;
        cnt = (mid / B) + (mid / C) - (mid / _lcm);
        if (cnt < A) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return (end + 1) % m;
}