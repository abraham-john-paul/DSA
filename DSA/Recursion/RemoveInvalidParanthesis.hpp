#include "../header.h"

void generate(vector<string>& ans, string& s, int i, int max, int openCount, int closeCount) {
    if (i == max) {
        if (openCount == closeCount) {
            ans.push_back(s);
        }
        return;
    }

    if (s[i] != '(' || s[i] != ')') {
        s.push_back(s[i]);
        generate(ans, s, i + 1, max, openCount, closeCount);
        s.pop_back();
    } else {
        if (s[i] == '(') {
            s.push_back('(');
            generate(ans, s, i + 1, max, openCount + 1, closeCount);
            s.pop_back();
        } else {
            s.push_back(')');
            if (closeCount + 1 <= openCount) {
                generate(ans, s, i + 1, max, openCount, closeCount + 1);
                s.pop_back();
            }
        }
        generate(ans, s, i + 1, max, openCount, closeCount);
    }
}

vector<string> solve(string A) {
    vector<string> ans;
    string s;
    s.reserve(A.size());
    generate(ans, s, 0, A.size(), 0, 0);

    return ans;
}