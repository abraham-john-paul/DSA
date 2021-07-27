#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    const int n = A.size();
    vector<int> prefixSum(n, 0);
    for (int i = 1; i < n; i++) {
        prefixSum[i] = ((A[i] >= A[i - 1]) ? 0 : 1);
    }
    prefixSum.front() = 0;

    partial_sum(prefixSum.begin(), prefixSum.end(), prefixSum.begin());

    for (int e : prefixSum) {
        cout << e << " ";
    }
    cout << "\n";

    vector<int> ans(B.size());
    int k = 0; 
    int left;
    int right; 
    for (const auto query : B) {
        left = query.front() - 1;
        right = query.back() - 1;
        if (left == 0) {
            ans[k++] = (prefixSum[right] == 0);
        } else {
            ans[k++] = (prefixSum[right] - prefixSum[left] == 0);
        }
    }

    return ans;
}