#include "../header.h"

int braces(string A) {
    int nOps = 0;
    int nCompleteBraces = 0;
    stack<char> st;
    for (const char c : A) {
        switch(c) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
                st.push(c);
                break;
            case ')':
                if (st.empty()) {
                    return 1;
                } else {
                    if (st.top() == '(') {
                        return 1;
                    }
                    st.pop(); // popping op
                    st.pop(); // popping (
                }
                break;
            default:
                continue;
        }
    }
    return 0;
}
