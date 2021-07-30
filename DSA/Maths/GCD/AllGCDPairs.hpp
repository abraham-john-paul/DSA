#include "../../header.h"

vector<int> solve(vector<int> &A) {
    const int nA = A.size();
    int nAns = log2(nA);
    vector<int> ans;
    ans.reserve(nA);
    
    unordered_map<int, int> um;
    for (int i = 0; i < nA; i++) {
        um[A[i]]++;
    }

    sort(A.begin(), A.end());
    
    for (int i = nA -1; i >=0; i--) {
        if (um[A[i]] <= 0) {
            continue;
        }

        for (const int e : ans) {
            int x = __gcd(e, A[i]);
            um[x] -= 2;
        }
        ans.push_back(A[i]);
        um[A[i]]--;
    }
    return ans;
}
