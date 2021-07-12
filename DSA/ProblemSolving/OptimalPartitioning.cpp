#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int solve(vector<int>& A) {
    int ans = INT_MAX;
    const int n = A.size();
    
    sort(A.begin(), A.end());

    for (int i = 1; i < n; i++) {
        ans = min(ans, A[i] - A[i - 1]);
    }

    return ans;
}

int main() {
    vector<int> A = {2, 1, 3, 2, 4, 3};
    cout << solve(A);
    return 0;
}