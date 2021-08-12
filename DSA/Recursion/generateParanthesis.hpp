#include "../header.h"

const string open = "(";
const string close = ")";

void generateParenthesisRec(vector<string>& ans, string cur, const int A, int openCount, int closeCount) {
    if (cur.size() == A * 2) {
        ans.push_back(cur);
        return;
    }

    if (openCount < A) {
        generateParenthesisRec(ans, cur + open, A, openCount + 1, closeCount);
    }
    
    if (openCount > closeCount) {
        generateParenthesisRec(ans, cur + close, A, openCount, closeCount + 1);
    }
}

vector<string> generateParenthesis(int A) {
    vector<string> ans;
    
    generateParenthesisRec(ans, "", A, 0, 0);

    return ans;
}