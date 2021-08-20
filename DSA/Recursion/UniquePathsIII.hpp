#include "../header.h"

void backtrack(vector<vector<int>>& A, int& ans, int i, int j) {
    const int nRow = A.size();
    const int nCol = A[0].size();

    if (A[i][j] == 2)  {
        for (int r = 0; r < nRow; r++) {
            for (int c = 0; c < nCol; c++) {
                if (A[r][c] == 0) {
                    return;
                }
            }
        }
        ans++;
        return;
    }

    int prev = A[i][j]; 
    if (i + 1 < nRow && A[i + 1][j] != -1) {
        i++;
        A[i][j] = -1;
        backtrack(A, ans, i, j);
        A[i][j] = prev;
        i--;
    }

    if (j + 1 < nCol && A[i][j + 1] != -1) {
        j++;
        A[i][j] = -1;
        backtrack(A, ans, i, j);
        A[i][j] = prev;
        j--;
    }

    if (i - 1 > -1 && A[i - 1][j] != -1) {
        i--;
        A[i][j] = -1;
        backtrack(A, ans, i, j);
        A[i][j] = prev;
        i++;
    }

    if (j - 1 > -1 && A[i][j - 1] != -1) {
        j--;
        A[i][j] = -1;
        backtrack(A, ans, i, j);
        A[i][j] = prev;
        j++;
    }
}

pair<int, int> findStart(const vector<vector<int> > &A, int start) {
    const int nRow = A.size();
    const int nCol = A[0].size();
    for (int r = 0; r < nRow; r++) {
        for (int c = 0; c < nCol; c++) {
            if (A[r][c] == start) {
                return {r, c};
            }
        }
    }
    return {-1, -1};
}

int solve(vector<vector<int> > &A) {
    auto p = findStart(A, 1);
    int ans = 0;
    backtrack(A, ans, p.first, p.second);
    return ans;
}