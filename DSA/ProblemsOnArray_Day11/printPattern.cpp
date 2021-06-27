#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> printPattern(int A) {
    vector<vector<int>> v(A, vector<int>(A, 0));
    int i, j;
    int n;
    for (i = 0; i < A; i++) {
        n = 1;
        for(j = A - 1; j >= A - i - 1; j--) {
            v[i][j] = n++;
        }
    }

    return v;
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
    int a;
    cin >> a;

    auto matrix = printPattern(a);
    print(matrix);
    return 0;
}