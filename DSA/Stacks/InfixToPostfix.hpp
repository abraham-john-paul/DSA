#include "../header.h"

unordered_map<char, int> opPrecedence = {
    {'^', 3},
    {'/', 2},
    {'*', 2},
    {'+', 1},
    {'-', 1}
};

string Solution::solve(string A) {
    stack<char> stk;
    const int nA = A.size();
    string ans;
    ans.reserve(nA);
    char c;
    for (char c : A) {
        switch (c) {
            case '^':
            case '/':
            case '*':
            case '+':
            case '-': {
                while (!stk.empty() && stk.top() != '(' && opPrecedence[stk.top()] >= opPrecedence[c]) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
                stk.push(c);
                break;
            }
            case '(': {
                stk.push(c);
                break;
            }
            case ')': {
                while (stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                stk.pop();
                break;
            }
            default: { // operands
                ans.push_back(c);
            }
        }
    }
    
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    
    return ans;
}
