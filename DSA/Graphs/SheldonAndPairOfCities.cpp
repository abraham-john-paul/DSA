#include "../header.h"

vector<int> solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F, vector<int> &G, vector<int> &H) {
    vector<vector<int>> dist(A + 1, vector<int>(A + 1, INT_MAX));
    int u, v, d;

    for (int i = 0; i < B; i++) {
        u = D[i];
        v = E[i];
        d = F[i];
        dist[u][v] = d;
        dist[v][u] = d;
    }

    for (int c = 1; c <= A; c++) {
        for (u = 1; u <= A; u++) {
            for (v = 1; v <= A; v++) {
                if (u == c || v == c) continue;
                if (u == c && v == c) {
                    dist[u][v] = 0;
                } else if (dist[c][v] != INT_MAX && dist[u][c] != INT_MAX) {
                    dist[u][v] = min(dist[u][v], dist[u][c] + dist[c][v]);
                }
            }
        }
    }

    vector<int> ans(C);
    for (int i = 0; i < C; i++) {
        u = G[i];
        v = H[i];
        ans[i] = (dist[u][v] == INT_MAX) ? -1 : dist[u][v];
    }

    return ans;
}