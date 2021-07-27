#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    const int n = A.size();
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (i != A[i]) {
            swap(A[i], A[A[i]]);
            ans++;
            continue;
        }
        i++;
    }

    return ans;
}