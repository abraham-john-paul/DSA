#include "../../header.h"

vector<int> nextPermutation(vector<int> &A) {
    const int n = A.size();
    cout << n << " ";
    set<int> s;
    vector<int> ans(A.begin(), A.end());
    int j;
    int pos = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            pos = i + 1;
            break;
        }
    }

    sort(ans.begin() + pos, ans.end());
    if (pos != 0) {
        auto itr = upper_bound(ans.begin() + pos, ans.end(), ans[pos - 1]);
        swap(*itr, ans[pos - 1]);
    }

    return ans;
}