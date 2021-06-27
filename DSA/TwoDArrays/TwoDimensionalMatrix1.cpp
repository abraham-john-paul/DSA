#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
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

int findIndexOfMax(vector<vector<int>>& v, int r, int c) {
    int i = 0;
    auto itr = lower_bound(v[i].begin(), v[i].end(), 1);
    int row = (itr == v[i].end()) ? -1 : 0;
    int col = itr - v[i].begin();
    i++;

    while (i < r) {
        if(col == 0) {
            break;
        }
        for (int j = col - 1; j >= 0; j--) {
            if(v[i][j] == 0) {
                break;
            } else {
                col--;
                row = i;
            }
        }
        i++;
    }
    
    return row; 
}

int searchElement(vector<vector<int> > &A, int B) {
    if (A.empty()) {
        return -1;
    }
    int row = 0;
    auto itr = lower_bound(A[row].begin(), A[row].end(), B);
    int col = itr - A[row].begin();
    if (*itr == B) {
        return col;
    }
    row++;
    const int nRows = A.size();
    while (row < nRows) {
        auto itr = lower_bound(A[row].begin(), A[row].end(), B);
        col = itr - A[row].begin();
        if (A[row][col] == B) {
            return row * 1009 + col;
        }
        row++;
    }

    return -1;
}

int main() {
    // vector<vector<int>> v = {
    //     {0,0,0,0,0,1},
    //     {0,0,1,1,1,1},
    //     {0,0,0,0,0,0},
    //     {1,1,1,1,1,1},
    //     {0,0,0,1,1,1}
    // };

    vector<vector<int>> a = { 
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} 
    };


    // auto row = findIndexOfMax(v, v.size(), v[0].size());
    // cout << "\nbiggest no. is at row " << row;
    int index = searchElement(a, 8);
    cout << "index : " << index;

    return 0;
}