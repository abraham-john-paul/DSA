#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<vector<int> > &A) {
    int ans = 0;
    int n = A.size();
    if (n == 2) {
        int a, b, c, d;
        a = A[0][0];
        b = A[0][1];
        c = A[1][0];
        d = A[1][1];
        ans += A[0][0] * A[1][1] - A[1][0] * A[0][1];
    } else if (n == 3) {
        ans += A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
        ans -= A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]);
        ans += A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    }

    return ans;
}

int main() {
    vector<vector<int> > A = {
      {6, 1, 1},
      {4, -2, 5},
      {2, 8, 7}, 
    };
    cout << solve(A);
    return 0;
}