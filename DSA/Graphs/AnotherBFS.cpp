#include "../header.h"

int solve(int A, vector<vector<int> > &B, int C, int D) {
    vector<vector<int>>adjList(A << 1, vector<int>());
    int u, v, wgt;
    int node = A;
    for (auto& e : B) {
        u = e[0];
        v = e[1];
        wgt = e[2];
        if (wgt == 2) {
            adjList[u].push_back(node);
            adjList[node].push_back(u);
            adjList[node].push_back(v);
            adjList[v].push_back(node);
            node++;
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    queue<int> q;
    vector<int> visited(A << 2, -1);
    visited[C] = 0;
    q.push(C);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : adjList[u]) {
            if (visited[v] == -1) {
                visited[v] = visited[u] + 1;
                q.push(v);
            }
            if (v == D) {
                return visited[v];
            }
        }
    }
    return -1;
}