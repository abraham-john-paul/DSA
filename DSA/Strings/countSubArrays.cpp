#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solve(string A) {
    const int n = A.size();
    int ans = 0;
    char c;
    for (int i = 0; i < n; i++) {
        c = A[i];
        cout << c << " " << ans << "\n";

        switch (c) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u': {
                ans += (n - i);
                break;
            }
        }
    }
    return 0;
}

int main() {
    string s = "pGpEusuCSWEaPOJmamlFAnIBgAJGtcJaMPFTLfUfkQKXeymydQsdWCTyEFjFgbSmknAmKYFHopWceEyCSumTyAFwhrLqQXbWnXSn";
    auto res = solve(s);
    cout << endl;
    cout << res;
    return 0;
}