#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &A) {
    if (A.empty()) {
        return {};
    }

    const int n = A.size();
    vector<int> ans(n);
    int sum = A.back() + 1;
    ans.back() = (sum > 9) ? 0 : sum;
    int carry = (A.back() + 1 > 9) ? 1 : 0;
    for (int i = n - 2; i >= 0; i--) {
        sum = A[i] + carry;
        ans[i] = (sum > 9) ? 0 : sum;
        carry = (sum > 9) ? 1 : 0;
    } 
    if (carry) {
        ans.insert(ans.begin(), carry);
    }

    ans.erase(ans.begin(), find_if(ans.begin(), ans.end(), [](int a) { return a != 0; }));

    return ans;
}