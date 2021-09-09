#include "../header.h"

#define ll long long
int solve(vector<int> &A) {
    ll start = 0, end = 0;
    unordered_set<int> us;
    ll ans = 0;
    ll extraEnd = -1;
    const int m = 1e9 + 7;
    const int nA = A.size();
    
    while (end < nA) {
        if (us.find(A[end]) == us.end()) {
            us.insert(A[end]);
            end++;
        } else {
            ans = (ans + ((end - start) * (end - start + 1)) / 2) % m;
            if (extraEnd != -1) {
                ans = (ans - ((extraEnd - start) * (extraEnd - start + 1)) / 2) % m;
            }
            extraEnd = end;
            while (us.find(A[end]) != us.end()) {
                us.erase(A[start]);
                start++;
            }
        }
    }
    ans = (ans + ((end - start) * (end - start + 1)) / 2) % m;
    if (extraEnd != -1) {
        ans = (ans - ((extraEnd - start) * (extraEnd - start + 1)) / 2) % m;
    }
    return ans % m;
}
