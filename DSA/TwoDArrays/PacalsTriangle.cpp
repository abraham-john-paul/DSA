#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& v);

vector<vector<int>> generatePascalsTriangle(int A) {
    vector<vector<int>> res;
    vector<int> row;

    for (int iRow = 0; iRow < A; iRow++) {
        row = vector<int>(iRow + 1, 1);
        for (int iCol = 1; iCol < iRow; iCol++) {
            row[iCol] = (res.back())[iCol] + (res.back())[iCol - 1];
        }
        res.push_back(row);
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
    int A;
    cout << "\nEnter the value of A : ";
    cin >> A;

    auto matrix = generatePascalsTriangle(A);
    print(matrix);

    return 0;
}