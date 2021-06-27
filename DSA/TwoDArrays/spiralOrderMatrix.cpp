#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>>& v);

vector<vector<int>> generateMatrix(int A) {
    vector<vector<int>> res(A, vector<int>(A));
    int top = 0;
    int bottom = A - 1;
    int left = 0;
    int right = A - 1;
    int i;
    int n = 1;
    while ((top <= bottom) && (left <= right)) {
        for (i = left; i <= right; i++) {
            res[top][i] = n++;
        }
        top++;

        for (i = top; i <= bottom; i++) {
            res[i][right] = n++;
        }
        right--;

        for (i = right; i >= left; i--) {
            res[bottom][i] = n++;
        }
        bottom--;

        for (i = bottom; i >= top; i--) {
            res[i][left] = n++;
        }
        left++;
    }

    return res;
}

void print(vector<vector<int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
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

    auto matrix = generateMatrix(A);
    print(matrix);

    return 0;
}