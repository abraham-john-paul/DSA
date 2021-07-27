#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin >> t;
    ll ans = 0;
    ll n, k;
    ll i, value;
    while (t--) {
        cin >> n >> k;
        ans = 0;
        if (k != 0) {
            value = 1 << n - 1;
            ll j = k < value ? k : value; 
            ans = (value << 1) * j;
            cout << ans << "\n";
        }
    }

    return 0;
}