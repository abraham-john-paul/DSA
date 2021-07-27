#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r1, w1, c1;
        cin >> r1 >> w1 >> c1;
        int A = 0;

        int r2, w2, c2;
        cin >> r2 >> w2 >> c2;
        int B = 0;
        
        if (r1 < r2) {
            A++;
        } else {
            B++;
        }

        if (c1 < c2) {
            A++;
        } else {
            B++;
        }

        if (w1 < w2) {
            A++;
        } else {
            B++;
        }

        if (A > B) {
            cout << "A\n";
        } else {
            cout << "B\n";
        }

    }

    return 0;
}