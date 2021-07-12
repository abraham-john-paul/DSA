#include <iostream>
#include <vector>
using namespace std;

int findSum(const vector<vector<int>> &A, int i1, int j1, int i2, int j2) {
    int m = 1000000007;
    int a = A[i2][j2];
    int b = A[i2][j1 - 1];
    int c = A[i1 - 1][j2];
    int d = A[i1 - 1][j1 - 1];
    if (i1 == 0 && j1 == 0) {
        return a;        
    } else if (i1 == 0) {
        return (a % m + -b % m + m) % m;
    } else if (j1 == 0) {
        return (a % m + -c % m + m) % m;
    } else {     
        int ans = ((a % m + -b % m) % m + m) % m;
        ans = ((ans % m + -c % m) % m + m) % m;
        ans = ((ans % m + d % m) % m + m) % m;
        return ans;
    }
}

vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int i, j;
    int m = A.size();
    int n = (m != 0) ? A[0].size() : 0;

    for (i = 0; i < m; i++) { // row wise prefix sum
        for (j = 1; j < n; j++) {
            A[i][j] += A[i][j - 1];
        }
    }

    for (j = 0; j < n; j++) { // column wise prefix sum
        for (i = 1; i < m; i++) {
            A[i][j] += A[i - 1][j];
        }
    }

    int nQ = B.size();
    vector<int> ans;
    ans.reserve(nQ);
    for (i = 0; i < nQ; i++) {
        // cout << B[i] - 1 << " " <<  C[i] - 1 << " " <<  D[i] - 1 << " " <<  E[i] - 1 << "\n";
        ans.push_back(findSum(A, B[i] - 1, C[i] - 1, D[i] - 1, E[i] - 1));
    }

    return ans;
}

int main() {
    vector<vector<int> > A = {
        {5, 17, 100, 11},
        {0, 0, 2, 8}
    };
    vector<int> B = {1, 1}; 
    vector<int> C = {1, 4}; 
    vector<int> D = {2, 2}; 
    vector<int> E = {2, 4};

    auto ans = solve(A, B, C, D, E);
    for (int e : ans) {
        cout << e << " ";
    }

    return 0;
}