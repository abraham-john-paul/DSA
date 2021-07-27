#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int a, b;
    int total = 0;
    while (t--) {
        cin >> a >> b;
        total = a + b;
        if (total > 60) {
            cout << "4\n";
        } else if (total <= 60 && total >= 11) {
            cout << "3\n";
        } else if (total <= 10 && total >= 3) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
        total = 0;
    }

    return 0;
}