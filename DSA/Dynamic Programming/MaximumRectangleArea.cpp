#include <../header.h>

int findMaxArea(const vector<int>& A) {
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

int maximalRectangle(vector<vector<int> > &A) {
    int nRow = A.size();
    int nCol = A[0].size();
    int ans = findMaxArea(A[0]);
    for (int i = 1; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (A[i][j]) {
                A[i][j] += A[i - 1][j];
            }
        }
        ans = max(ans, findMaxArea(A[i]));
    }

    return ans;
}
