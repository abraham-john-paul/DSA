#include "../header.h"

bool dfs(const vector<vector<int>>& adjList, vector<int>& visited, int src) {
    visited[src] = 1;
    for (int des : adjList[src]) {
        if (!visited[des]) {
            if (dfs(adjList, visited, des)) {
                return true;
            }
        } else {
            if (visited[des] == 1) {
                return true;
            } 
        }
    }
    visited[src] = 2;
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adjList(A, vector<int>());
    vector<int> visited(A);
    int u, v;
    for (auto& edge: B) {
        u = edge[0] - 1;
        v = edge[1] - 1;
        adjList[u].push_back(v);
    }
    bool ans;
    for (int i = 0; i < A; i++) {
        if (!visited[i]) {
            ans = dfs(adjList, visited, i);
            if (ans) {
                break;
            }
        }
    }

    return ans;
}
