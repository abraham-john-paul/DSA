#include "../header.h"

void generate(set<string>& ans, string& s, int i, const string& A, int openCount, int closeCount) {
    if (i == A.size()) {
        if (openCount == closeCount) {
            if (ans.empty() || ans.begin()->size() == s.size() && *ans.begin() != s) {
                ans.insert(s);
            }
        }
        return;
    }
    
    if (A[i] != '(' && A[i] != ')') {
        s.push_back(A[i]);
        generate(ans, s, i + 1, A, openCount, closeCount);
        s.pop_back();
    } else {
        if (A[i] == '(') {
            s.push_back(A[i]);
            generate(ans, s, i + 1, A, openCount + 1, closeCount);
            s.pop_back();
        } else {
            if (closeCount < openCount) {
                s.push_back(A[i]);
                generate(ans, s, i + 1, A, openCount, closeCount + 1);
                s.pop_back();
            }
        }
        generate(ans, s, i + 1, A, openCount, closeCount);
    }
}

vector<string> solve(string A) {
    set<string> ans;
    string s;

    generate(ans, s, 0, A, 0, 0);

    return vector<string>(ans.begin(), ans.end());
}
