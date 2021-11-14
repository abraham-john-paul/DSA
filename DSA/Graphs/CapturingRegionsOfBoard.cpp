    #include "../header.h"
    
    const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char> >& A, vector<vector<bool>>& visited, int i, int j) {
        int nRow = A.size();
        int nCol = A[0].size();
        if (i < 0 || i >= nRow || j < 0 || j >= nCol) {
            return false;
        }
        if (A[i][j] == 'X') {
            return true;
        }
        visited[i][j] = true;
        int u, v;
        bool ans = true;
        for (const auto& d : directions) {
            u = i + d[0];
            v = j + d[1];
            ans &= dfs(A, visited, u, v);
            if (!ans) {
                break;
            }
        }
        
        if (ans) {
            A[i][j] = 'X';
        }
        return ans;
    }

    void solve(vector<vector<char> > &A) {
        int nRow = A.size();
        int nCol = A[0].size();
        vector<vector<bool>> visited(nRow, vector<bool>(nCol));
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                if (A[i][j] == 'O' && !visited[i][j]) {
                    dfs(A, visited, i, j);
                }
            }
        }
    }
