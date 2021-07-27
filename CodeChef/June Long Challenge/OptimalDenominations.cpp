#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b) {
    int t;
    while (b == 0) {
        t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main() {
    using ll = long long;
    int t;
    cin >> t;
    ll N;
    vector<int> A;
    ll i, e;
    while(t--) {
        cin >> N;
        auto A = vector<ll>(N, 0);
        auto prefixGCD = vector<ll>(N, 0);
        auto suffixGCD = vector<ll>(N, 0);
        ll total = 0;
        for (i = 0; i < N; i++) {
            cin >> e;
            A[i] = e;
            total += e;
        }

        if (N == 1) {
            return 1;
        }

        ll start = 1;
        ll end = N - 2;
        prefixGCD.front() = A.front();
        suffixGCD.back() = A.back();
        for (i = 1; i < N; i++) {
            prefixGCD[start] = findGCD(A[start], prefixGCD[start - 1]);
            suffixGCD[end] = findGCD(A[end], suffixGCD[end + 1]);
            start++;
            end--;
        }

        ll ans = total / prefixGCD.back();
        ll den;
        for (i = 0; i < N; i++) {
            den = (ll)findGCD((i - 1 < 0) ? 0 : prefixGCD[i - 1], (i + 1 > N - 1) ? 0 : suffixGCD[i + 1]);
            ans = min(ans, (total - A[i]) / den + (ll)1);
        }

        cout << ans << "\n";
    }

    return 0;
}