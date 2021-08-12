#include "../header.h"

void generate(const vector<int> &A, const int B, 
    vector<vector<int> >& ans, vector<int>& cur,
    int i, int sum) {
        if (sum == B) {
            ans.push_back(cur);
            return;
        }

        if (sum > B || i == A.size()) {
            return;
        }
        unordered_set<int> found;
        for (int j = i; j < A.size(); j++) {
            if (found.find(A[j]) != found.end()) {
                continue;
            }
            found.insert(A[j]);
            sum += A[j];
            cur.push_back(A[j]);
            generate(A, B, ans, cur, j + 1, sum);
            cur.pop_back();
            sum -= A[j];
        }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    vector<vector<int> > ans;
    vector<int> cur;
    cur.reserve(A.size());
    sort(A.begin(), A.end());

    generate(A, B, ans, cur, 0, 0);

    return ans;
}