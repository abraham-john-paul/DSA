#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    const int nA = A.size();
    const int nB = B.size();
    const int nC = C.size();
    int a = A[i];
    int b = B[j];
    int c = C[k];
    int ans = INT_MAX;
    int curMin;
    while (i < nA && j < nB && k < nC) {
        curMin = min(min(a, b), c);
        ans = min(ans, max(max(a, b), c) - curMin);
        if (a == curMin) {
            i++;
            a = A[i];
        } else if (b == curMin) {
            j++;
            b = B[j];
        } else {
            k++;
            c = C[k];
        }
    }

    return ans;
}

int main() {
    vector<int> A = { 1, 4, 5, 8, 10 };
    vector<int> B = { 6, 9, 15 };
    vector<int> C = { 2, 3, 6, 6 };

    cout << solve(A, B, C);
    
    return 0;
}
