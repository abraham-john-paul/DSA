#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    int ans = INT_MAX;
    const int n = A.size();
    
    for (int i = 0; i <= n - B; i++) {
        ans = min(ans, A[i + B - 1] - A[i]);
    }

    return ans;
}

int main() {
    vector<int> A = {10, 12, 10, 7, 5, 22};
    int B = 4;
    cout << solve(A, B);
    return 0;
}