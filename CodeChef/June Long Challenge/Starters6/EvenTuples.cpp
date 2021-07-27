#include <bits/stdc++.h>

using namespace std;

int main() {
    using ll = long long;
    int t;
    cin >> t;
    int n, q;
    int l, r;
    while (t--) {
        cin >> n >> q;
        
        vector<int> A(n);
        vector<ll> prefixOddCount(n + 1);
        int i = 1;
        for (int& e : A) {
            cin >> e;
            if (e & 1) {
                prefixOddCount[i] = prefixOddCount[i - 1] + 1;
            } else {
                prefixOddCount[i] = prefixOddCount[i - 1];
            }
            i++;
        }

        for (i = 0; i < q; i++) {
            ll ans = 0;
            cin >> l >> r;
            ll n = r - l + 1;
            ll nOdd = prefixOddCount[r] - prefixOddCount[l - 1];
            ll nEven = n - nOdd;
            ans = (nEven * (nEven - 1) * (nEven - 2)) / 6;
            ans += ((nOdd * (nOdd - 1)) / 2) * nEven;
            cout << ans << "\n";
        }
    }

    return 0;
}