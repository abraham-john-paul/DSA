#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int x, y;
    vector<int> v(6);
    iota(v.begin(), v.end(), 1);
    while (t--) {
        cin >> x >> y;
        auto itr = upper_bound(v.begin(), v.end(), x + y);
        cout << (float)(6 - (itr - v.begin())) / 6 << "\n";
    }

    return 0;
}