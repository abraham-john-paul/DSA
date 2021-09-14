#include "../header.h"

int solve(vector<vector<int> > &A) {
    const int nRow = A.size();
    const int nCol = A[0].size();
    vector<int> count(nCol);
    int r, c;
    long long ans = 0;
    long long height, width;
    stack<int> stk;
    for (r = 0; r < nRow; r++) {
        for (c = 0; c <= nCol; c++) {
            if (c < nCol) {
                if (A[r][c] == 1) {
                    count[c]++;
                } else {
                    count[c] = 0;
                }
            }
            while (!stk.empty() && ((c == nCol) || count[c] <= count[stk.top()])) {
                height = count[stk.top()];
                stk.pop();
                width = stk.empty() ? c : c - stk.top() - 1;
                ans = max(ans, height * width);
            } 
            if (c < nCol) {
                stk.push(c);
            }
        }
    }
    return ans;
}
