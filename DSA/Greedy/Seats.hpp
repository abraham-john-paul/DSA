#include "../header.h"

int Solution::seats(string A) {
    int m = 1e7 + 3;
    vector<int> pos;
    int cnt = 0;
    int i = 0;
    for (char a : A) {
        if (a == 'x') {
            pos.push_back(i - cnt);
            cnt++;
        }
        i++;
    }
    if (cnt < 2) {
        return 0;
    }
    int median = pos[(cnt - 1) >> 1];
    int ans = 0;
    for (int s : pos) {
        ans = (ans + abs(s - median)) % m;
    }

    return ans;
}