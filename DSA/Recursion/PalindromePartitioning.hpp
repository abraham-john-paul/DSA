#include "../header.h"

bool isPalindrome(const string& A, int start, int end) {

    while (start < end) {
        if (A[start++] != A[end--]) {
            return false;
        }
    }
    return true;
}

void backtrack(vector<vector<string>>& ans, const string& A, vector<string>& cur, int start) {
    const int nA = A.size();

    if (start == nA) {
        ans.push_back(cur);
        return;
    }
    
    for (int i = start; i < nA; i++) {
        if (isPalindrome(A, start, i)) {
            cur.push_back(A.substr(start, i - start + 1));
            backtrack(ans, A, cur, i + 1);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string A) {
    vector<vector<string>> ans;
    vector<string> cur;
    
    backtrack(ans, A, cur, 0);

    return ans;
}