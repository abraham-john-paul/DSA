#include <bits/stdc++.h>

using namespace std;

void reverse(vector<int>& row) {
    int start = 0;
    int end = row.size() - 1;

    while (start < end) {
        swap(row[start], row[end]);
        start++;
        end--;
    }
}

void solve(vector<vector<int> > &A) {
    int r = A.size();
    if (r == 0) {
        return;
    }
    int c = A[0].size();

    // Taking transpose of A
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < i; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    // Reversing each row
    for (int i = 0; i < r; i++) {
        reverse(A[i]);
    }
}
