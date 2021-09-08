#include "../header.h"

int solve(string A) {
    stack<char> st;
    char open;
    for (const char c : A) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ')':
                if (st.empty() || st.top() != '(') {
                    return 0;
                } else {
                    st.pop();
                }
                break;
            case '}':
                if (st.empty() || st.top() != '{') {
                    return 0;
                } else {
                    st.pop();
                }
                break;
            case ']':
                if (st.empty() || st.top() != '[') {
                    return 0;
                } else {
                    st.pop();
                }
                break;
        }
    }
    return st.empty() ? 1 : 0;
}
