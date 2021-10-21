#include "../header.h"

unordered_map<char, char> closed;
unordered_map<char, char> open;

void solve(const string& A, vector<int>& dp) {
    int nA = A.size();
    int idx;
    for (int i = 1; i <= nA; i++) {
        if (open.find(A[i - 1]) == open.end()) { // closed
            if (i - 2 > 0 && open.find(A[i - 2]) != open.end()) {
                if (A[i - 1] == open[A[i - 2]]) {
                    dp[i] = dp[i - 2] + 2;
                }
            } else {
                idx = (i - 1) - dp[i - 1] - 1;
                if (open.find(A[idx]) != open.end()) {
                    if (A[i - 1] == open[A[idx]])
                        dp[i] = dp[i - 1] + 2 + dp[idx];
                }
            }
        } 
    }
}

int Solution::LBSlength(const string A) {
    open.insert({'(', ')'});
    open.insert({'[', ']'});
    open.insert({'{', '}'});
    closed.insert({')', '('});
    closed.insert({'}', '{'});
    closed.insert({']', '['});
    const int nA = A.size();
    vector<int> dp(nA + 1);
    solve(A, dp);
    return *max_element(dp.begin(), dp.end());
}