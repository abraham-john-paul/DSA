#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A) {
    int ans = 0;
    const int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << A[i] << " " << A[j] << "\n";
            ans = (ans + (A[j] - A[i])) % 1000000007;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {5, 4, 2};
    cout << solve(A);
    return 0;
}