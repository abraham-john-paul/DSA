#include "../header.h"

struct Edge {
    int u;
    int v;
    int wgt;
};

bool isValid(int i, int j, int nRow, int nCol) {
    return (i >=0 && i < nRow) && (j >= 0 && j < nCol);
}

int solve(int A, int B, vector<vector<int> > &C) {
    vector<vector<int>> dist(A, vector<int>(B, INT_MAX));
    
    auto cmp = [](Edge& e1, Edge& e2) {
        return e1.wgt > e2.wgt;
    };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
    pq.push({0, 0, INT_MIN});
    
    const vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int u, v;
    int ans = INT_MIN;
    int i, j, k;
    while (!pq.empty()) {
        auto& e = pq.top();
        i = e.u;
        j = e.v;
        k = e.wgt;
        if (dist[i][j] == INT_MAX) {
            ans = max(ans, k);
            if (k == INT_MIN) k = 0;
            dist[i][j] = k;            
        }
        pq.pop();

        for (const auto& d : direc) {
            tie(u, v) = d;
            u += i;
            v += j;
            if (!isValid(u, v, A, B)) continue;
            if (dist[u][v] == INT_MAX) {
                pq.push({u, v, abs(C[i][j] - C[u][v])});
            }
        }

        
    }

    return ans;
}
