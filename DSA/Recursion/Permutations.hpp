#include "../header.h"

void permutations(vector<vector<int>>& ans, vector<int> A, int i) {
    const int n = A.size();
    if (i == n - 1) {
        ans.push_back(A);
        return;
    }
    for (int j = i; j < n; j++) {
        swap(A[i], A[j]);
        permutations(ans, A, i + 1);
    }
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int>> ans;
    permutations(ans, A, 0);

    return ans;
}