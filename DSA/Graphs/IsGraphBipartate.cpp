#include "../header.h"

bool dfs(const vector<vector<int>>& adjList, vector<int>& visited, int src, int parent, int color) {
    visited[src] = color;
    for (int dest : adjList[src]) {
        if (visited[dest] == 0) {
            if (!dfs(adjList, visited, dest, src, 3 - color)) {
                return false;
            }
        } else if (visited[dest] == color && parent != dest) {
            return false;
        }
    }

    return true;
}

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adjList(A, vector<int>());
    int u, v;
    for (auto& e : B) {
        u = e[0];
        v = e[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> visited(A);
    bool ans = true;
    for (int i = 0; i < A; i++) {
        if (visited[i] == 0) {
            ans &= dfs(adjList, visited, i, i, 1);
            if (!ans) break;
        }
    }

    return ans ? 1 : 0;
}
