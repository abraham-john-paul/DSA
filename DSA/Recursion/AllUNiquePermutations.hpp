#include "../header.h"

void generatePermuations(vector<vector<int> >& ans, vector<int> A,  int i) {
        const int n = A.size();
        if (i == n - 1) {
            ans.push_back(A);
            return;
        }

        unordered_set<int> found;
        for (int j = i; j < n; j++) {
            if (found.find(A[j]) != found.end()) {
                continue;
            }
            found.insert(A[j]);
            swap(A[i], A[j]);
            generatePermuations(ans, A, i + 1);
        }
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > ans;
    
    generatePermuations(ans, A, 0);
    
    return ans;
}