#include "../header.h"

int Solution::evalRPN(vector<string> &A) {
        unordered_map<string, function<int(int, int)>> opMap {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}
    };
    
    int a, b, res;
    stack<int> stk;

    for (const auto& s : A) {
        if (opMap.find(s) != opMap.end()) {
            b = stk.top();
            stk.pop();
            a = stk.top();
            stk.pop();

            auto fn = opMap[s];
            res = fn(a, b);
            
            stk.push(res);
        } else {
            stk.push(stoi(s));
        }
    }

    return stk.top();
}