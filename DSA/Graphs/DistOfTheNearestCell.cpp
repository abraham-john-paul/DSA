#include "../header.h"

const vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(const vector<vector<int> > &A, vector<vector<bool>>& visited, vector<vector<int>>& ans, 
    int i, int j) {
    int nRow = A.size();
    int nCol = A[0].size();
    if (i < 0 || i >= nRow || j < 0 || j >= nCol) {
        return INT_MAX;
    }
    if (A[i][j] == 1) {
        return 0;
    }
    if (visited[i][j]) {
        return ans[i][j] == 0 ? INT_MAX : ans[i][j];
    }
    visited[i][j] = true;
    int u, v;
    int dist = INT_MAX;
    for (const auto& d: directions) {
        auto res = dfs(A, visited, ans, i + d[0], j + d[1]);
        if (res != INT_MAX) {
            dist = min(dist, 1 + res);
        }
    }
    ans[i][j] = dist;
    return dist;
}

vector<vector<int> > solve(vector<vector<int> > &A) {
    int nRow = A.size();
    int nCol = A[0].size();
    vector<vector<int>> ans(nRow, vector<int>(nCol));
    vector<vector<bool>> visited(nRow, vector<bool>(nCol));
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (A[i][j] == 0) {
                visited[i][j] = false;
                ans[i][j] = dfs(A, visited, ans, i, j);
            }
        }
    }

    return ans;
}
