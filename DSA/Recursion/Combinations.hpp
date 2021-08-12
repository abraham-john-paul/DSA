#include "../header.h"

void combinations(vector<vector<int>>& ans, vector<int> cur, const int A, const int B, int i) {
    if (i > A + 1) {
        return;
    } 
    if (cur.size() == B) {
        ans.push_back(cur);
        return;
    }
    combinations(ans, cur, A, B, i + 1);
    cur.push_back(i);
    combinations(ans, cur, A, B, i + 1);
}

vector<vector<int> > combine(int A, int B) {
    vector<vector<int> > ans;
    vector<int> curCombination;
    curCombination.reserve(B);
    combinations(ans, curCombination, A, B, 1);
    reverse(ans.begin(), ans.end());
    return ans;
}