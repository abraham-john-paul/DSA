#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;
// mlog(n) solution
// int findIndexOfMax(vector<vector<int>>& v, int m, int n) {
//     int i = 0;
//     auto itr = lower_bound(v[i].begin(), v[i].end(), 1);
//     int row = (itr == v[i].end()) ? -1 : 0;
//     int col = itr - v[i].begin();
//     i++;

//     while (i < m) {
//         if(col == 0) {
//             break;
//         }
//         auto itr1 = v[i].begin() + col;
//         auto itr2 = lower_bound(v[i].begin(), itr1, 1);
//         if (itr1 != itr2) {
//             col = itr2 - v[i].begin();
//             row = i;
//         }
//         i++;
//     }
    
//     return row; 
// }

void print(vector<vector<int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotateMatrix(vector<vector<int>>& A) {
    const int r = A.size();
    const int c = A[0].size();
    int i, j;
    // swapping element across diagonal
    for (i = 0; i < r; i++) {
        for (j = 0; j < i; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    // rotate all rows
    int start, end;
    for (i = 0; i < r; i++) {
        start = 0;
        end = c - 1;
        while (start < end) {
            swap(A[i][start++], A[i][end--]);
        }
    }
}

int main() {
    constexpr int n = 3;
    
    vector<vector<int>> A(n, vector<int>(n, 0));
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = k++;
            A[j][i] = A[i][j];
        }
    }

    print(A);

    rotateMatrix(A);
    
    print(A);

    return 0;
}