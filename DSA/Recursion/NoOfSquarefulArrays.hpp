#include "../header.h"

void noOfSquarefulArraysRec(vector<int> A, int& cnt, int i) {
    const int n = A.size();
        if (i == n) {
        cnt++;
        return;
    }

    unordered_set<int> found;
    double m;
    for (int j = i; j < n; j++) {
        if (found.find(A[j]) != found.end()) {
            continue;
        }
        found.insert(A[j]);
        
        if (i - 1 >= 0) {
            m = sqrt(A[i - 1] + A[j]);
            if (floor(m) != ceil(m)) {
                continue;
            }
        }
        swap(A[i], A[j]);
        noOfSquarefulArraysRec(A, cnt, i + 1);
    }
}

int solve(vector<int> &A) {
    if (A.size() == 1) return 0;
    int ans = 0;
    noOfSquarefulArraysRec(A, ans, 0);
    return ans;
}
