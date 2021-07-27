#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    const int n = A.size();
    
    int curMax = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < curMax + A[i]) {
            curMax += A[i];
        } else {
            curMax = A[i];
        }

        ans = max(ans, curMax);
    }
    ans.erase(ans.begin(), find_if(ans.begin(), ans.end(), [](int a) -> bool {
        cout << a << " ";
         return a != 0; }));
    return ans;
}