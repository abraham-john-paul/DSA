#include "../header.h"

void simplifyExpression(const string& S, string& newS) {
    stack<char> stk;
    stk.push('+');

    int negSignCount = 0;
    char prevSign = '+';
    char prevChar;
    vector<int> freq(26);
    for (char c : S) {
        switch (c) {
            case '+':
            case '-': {
                prevSign = c;
                if (negSignCount & 1) {
                    c = (c == '+') ? '-' : '+';
                }
                newS += c;
                break;
            }
            case '(': {
                if (prevSign == '-') {
                    negSignCount++;
                }
                stk.push(prevSign);
                break;
            }
            case ')': {
                if (stk.top() == '-') {
                    negSignCount--;
                }
                stk.pop();
                break;
            }
            default: {
                if (prevChar == '(') {
                    prevSign = '+';
                }
                newS += c;

                if (prevSign == '+') {
                    freq[c - 'a'] += (negSignCount & 1) ? -1 : 1;
                } else {
                    freq[c - 'a'] += (negSignCount & 1) ? 1 : -1;
                }
            }
        } // end of switch
        prevChar = c;
    } // end of for

    newS.clear();
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            newS += '+';
        } else if (freq[i] < 0) {
            newS += '-';
        } else {
            continue;
        }
        newS += ('a' + i);
    }
} // end of simplifyExpression

int solve(string A, string B) {
    string newA;
    simplifyExpression(A, newA);
    
    string newB;
    simplifyExpression(B, newB);
    cout << newA << endl;
    cout << newB << endl;
    return newA == newB ? 1 : 0;
}