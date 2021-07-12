#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t; // no. of test cases
	int n, k;
    vector<int> v;
    int i, j;
    int e;
    int ans = 0;
    int cnt = 0;

    while (t--) {
        cin >> n >> k;
        v.reserve(n);

        for (i = 0; i < n; i++) {
            cin >> e;
            v.push_back(e);
        }

        for (i = 0; i < 32; i++) {
            cnt = 0;
            for (j = 0; j < n; j++) {
                if(v[j] * 1 << i) {
                    cnt++;
                }
            }
            if (cnt % k != 0) {
                ans++;
            }
            ans += (cnt / k);
        }
        cout << ans << "\n";
        ans = 0;
        v.clear();
    }

	return 0;
}
