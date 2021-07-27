#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n, m, l;
    while (t--) {
        cin >> n >> m >> l;
        int k;
        vector<vector<int>> mColorList;
        vector<int> colorLocation(n);
        int location = 0;
        for (int i = 0; i < m; i++) {
            cin >> k;
            vector<int> colors(k);
            int j = 0;
            for (int& color : colors) {
                cin >> color;
                colorLocation[color - 1] = location;
            }
            mColorList.push_back(colors);
            location++;
        }

        vector<int> strips(l);
        int ans = 0;
        int curLocation = -1;
        for (int& strip : strips) {
            cin >> strip;
            if (colorLocation[strip] != curLocation) {
                ans++;
                curLocation = strip;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}