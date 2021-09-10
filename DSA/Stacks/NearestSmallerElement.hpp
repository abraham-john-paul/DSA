#include "../header.h"

vector<int> prevSmaller(vector<int> &A) {
    const int nA = A.size();
    vector<int> ans(nA);
    stack<int> stk;
    for (int i = 0; i < nA; i++) {
        while (!stk.empty() && stk.top() >= A[i]) {
            stk.pop();
        }
        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(A[i]);
    }
    
    return ans;
}
