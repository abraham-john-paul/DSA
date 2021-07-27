#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
    const int n = A.size();
    if (n == 0) {
        return 0;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(A[i], i);
    }
    sort(v.begin(), v.end());
    auto itr = v.begin();
    int curMinIndex = itr->second;
    int ans = itr->second - curMinIndex;
    itr++;

    for (; itr != v.end(); itr++) {
        curMinIndex = min(curMinIndex, itr->second);
        ans = max(ans, itr->second - curMinIndex);
    }
    
    return ans;
}