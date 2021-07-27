#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    if (A.empty()) {
        return 0;
    }

    const int n = A.size();
    int sum = max(A[0] - B[n - 1], 0);

    for (int i = 1; i < n; i++) {
        sum += max(A[i] - B[i - 1], 0);
    }

    int ans = sum + A[0] - max(A[0] - B[n - 1], 0); 
    for (int i = 1; i < n; i++) {
        ans = min(ans, sum + A[i] - max(A[i] - B[i - 1], 0));
    }
    return ans;
}