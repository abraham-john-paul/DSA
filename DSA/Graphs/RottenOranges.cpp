#include "../header.h"

int solve(vector<vector<int> > &A) {
    int i, j;
    using pii = pair<int, int>;
    const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nRow = A.size();
    int nCol = A[0].size();
    queue<pii> q;
    int freshCount = 0;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            switch (A[i][j]) {
                case 1:
                    freshCount++;
                    break;
                case 2:
                    q.push(make_pair(i, j));
                    break;
            }
        }
    }
    int ans = 0;
    int n;
    int u, v;
    
    while (!q.empty()) {
        n = q.size();
        ans++;
        for (int k = 0; k < n; k++) {
            auto& rotten = q.front();
            i = rotten.first;
            j = rotten.second;
            
            for (const auto& d : directions) {
                u = i + d.first;
                v = j + d.second;
                if (u < 0 || u >= nRow || v < 0 || v >= nCol) continue;
                if (A[u][v] == 1) {
                    A[u][v] = 2;
                    q.push(make_pair(u, v));
                    freshCount--;
                }
            }
            q.pop();
        }
    }
    return freshCount != 0 ? -1 : ans - 1;
}