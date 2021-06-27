#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> generateAntiDiagonal(vector<vector<int>> &A) {
    vector<vector<int>> res;
    if (!A.empty()) {
        pair<int, int> iStart = {0, 0};
        pair<int, int> iEnd = {A.size(), A[0].size()};
        pair<int, int> iCur;
        vector<int> antiDiagonal;
        while ((iStart.first < iEnd.first) && (iStart.second < iEnd.second)) {
            iCur = iStart;
            antiDiagonal.reserve(iStart.second - iStart.first);
            while (iCur.second >= 0 && iCur.first < iEnd.first) {
                antiDiagonal.push_back(A[iCur.first++][iCur.second--]);
            }

            res.push_back(antiDiagonal);           
            antiDiagonal.clear();

            if (iStart.second < iEnd.second - 1) {
                iStart.second++;
            } else {
                iStart.first++;
            }
        }
    }
    return res;
}

void print(vector<vector<int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    constexpr int n = 3;
    
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    print(A);
    auto matrix = generateAntiDiagonal(A);
    print(matrix);

    return 0;
}