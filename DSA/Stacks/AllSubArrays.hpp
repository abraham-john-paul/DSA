#include "../header.h"

void prevMaxRight(vector<int>& maxRight, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = nA - 1; i >= 0; i--) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            stk.pop();
        }
        maxRight[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
}

void prevMaxLeft(vector<int>& maxLeft, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = 0; i < nA; i++) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            stk.pop();
        }
        maxLeft[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
}

int solve(vector<int> &A) {
    const int nA = A.size();

    vector<int> maxRight(nA);
    prevMaxRight(maxRight, A);

    vector<int> maxLeft(nA);
    prevMaxLeft(maxLeft, A);

    int ans = 0;

    for (int i = 0; i < nA; i++){
        if (maxRight[i] != -1) {
            ans = max(ans, A[i] ^ A[maxRight[i]]);
        }

        if (maxLeft[i] != -1) {
            ans = max(ans, A[i] ^ A[maxLeft[i]]);
        }
    }

    return ans;
}