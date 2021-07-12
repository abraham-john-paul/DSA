#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int g, c;
    while (t--) {
        cin >> g >> c;
        cout << (c * c) / (2 * g) << "\n";
    }

    return 0;
}