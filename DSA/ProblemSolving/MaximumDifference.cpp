#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits.h>

using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    const int n = A.size();

    for (int i = 1; i < n; i++) {
        A[i] += A[i - 1];
    }

    int ans  = abs(A.back() - 2 *A[B - 1]);
    for (int i = B; i < n; i++) {
        ans = max(ans, abs(2 * (A[i] - A[i - B]) - A.back()));
    }

    return ans;
}


int main () {
    vector<int> A = {1, 2, 3, 4, 5};
    int B = 2;
    cout << solve(A, B);
    return 0;
}