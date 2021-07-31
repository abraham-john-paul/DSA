#include "../../header.h"

vector<int> solve(vector<int> &A) {
    const int N = *max_element(A.begin(), A.end());
    vector<int> divisors(N + 1, 1);

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisors[j]++;
        }
    }

    const int n = A.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = divisors[A[i]];
    }

    return ans;
}