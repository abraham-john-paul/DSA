#include "../header.h"

#define ll long long
int largestRectangleArea(vector<int> &A) {
    ll ans = 0;
    const int nA = A.size();
    stack<int> stk;
    int height, width;
    for (int i = 0; i <= nA; i++) {
        while (!stk.empty() && (i == nA ||  A[stk.top()] >= A[i])) {
            height = A[stk.top()];
            stk.pop();
            if (stk.empty()) {
                width = i;
            } else {
                width = i - stk.top() - 1; 
            }
            ans = max(ans, (ll)height * width);
        }
        stk.push(i);
    }
    
    return ans;
}