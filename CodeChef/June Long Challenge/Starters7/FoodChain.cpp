#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int e, k;
    int ans;
    while (t--) {
        ans = 1;
        cin >> e >> k;
        while (e / k != 0) {
            e /= k;
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}