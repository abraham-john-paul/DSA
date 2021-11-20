#include "../header.h"

void dfs(const vector<vector<int>>& adjList, vector<bool>& visited, int src) {
    visited[src] = true;
    for (int v : adjList[src]) {
        if (!visited[v]) {
            dfs(adjList, visited, v);
        }
    }
}

int solve(vector<int> &A, const int B, const int C) {
    int nA = A.size();
    vector<vector<int>> adjList(nA + 1, vector<int>());
    for (int i = 1; i < nA; i++) {
        adjList[A[i]].push_back(i + 1);
    }
    vector<bool> visited(nA + 1);
    dfs(adjList, visited, C);
    return visited[B];
}