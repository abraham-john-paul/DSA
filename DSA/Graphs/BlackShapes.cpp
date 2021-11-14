#include "../header.h"

void dfs(const vector<string> &A, vector<vector<bool>>& visited, int i, int j) {
    int nRow = A.size();
    int nCol = A[0].size();
    if (i < 0 || i >= nRow || j < 0 || j >= nCol || A[i][j] == 'O' || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    dfs(A, visited, i, j + 1);
    dfs(A, visited, i, j - 1);
    dfs(A, visited, i + 1, j);
    dfs(A, visited, i - 1, j);
}

int black(vector<string> &A) {
    int nRow = A.size();
    int nCol = A[0].size();
    vector<vector<bool>> visited(nRow, vector<bool>(nCol));
    int ans = 0;
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (A[i][j] == 'X' && !visited[i][j]) {
                ans++;
                dfs(A, visited, i, j);
            }
        }
        return ans;
    }
}