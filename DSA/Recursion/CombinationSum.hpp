#include "../header.h"

void generate(const set<int>& s, const int B, vector<vector<int>>& ans, vector<int>& cur, std::set<int>::iterator itr, int sum) {
    if (sum == B) {
        ans.push_back(cur);
        return;
    }
    if (sum > B || itr == s.end()) {
        return;
    }

    for (auto j = itr; j != s.end(); j++) {
        if (sum + (*j) <= B) {
            cur.push_back(*j);
            sum += (*j);
            generate(s, B, ans, cur, j, sum);
            sum -= (*j);
            cur.pop_back();
        } else {
            break;
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> cur;
    set<int> s(A.begin(), A.end());
    generate(s, B, ans, cur, s.begin(), 0);
    sort(ans.begin(), ans.end());
    return ans;
}