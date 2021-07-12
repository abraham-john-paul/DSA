#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solve(vector<vector<int> > &A) {
    if (A.empty()) {
        return {};
    }
    const int nRow = A.size();
    const int nCol = A[0].size();
    
    vector<int> ans;
    ans.reserve(nCol);
    
    int colSum;

    for (int c = 0; c < nCol; c++) {
        colSum = 0;
        for (int r = 0; r < nRow; r++) {
            colSum += A[r][c];
        }
        ans.push_back(colSum);
    }

    return ans;
}


int main () {
    vector<vector<int>> A = {
                            {1,2,3,4},
                            {5,6,7,8},
                            {9,2,3,4}
                            };
    auto ans = solve(A);

    for (const int elem : ans) {
        cout << elem << " ";
    }

    return 0;
}