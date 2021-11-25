#include "../header.h"

int dfs(vector<vector<int>>& adjList, vector<bool>& visited, int u, int& ans) {
    int mx1 = INT_MIN;
    int mx2 = INT_MIN;
    int dist;
    visited[u] = true;

    for (int v : adjList[u]) {
        if (!visited[v]) {
            dist = 1 + dfs(adjList, visited, v, ans);
            if (dist > mx1) {
                mx2 = mx1;
                mx1 = dist;
            } else if (dist > mx2) {
                mx2 = dist;
            }
        }
    }
    if (mx2 == INT_MIN) {
        mx2 = 0;
    }
    ans = max(ans, mx1 + mx2);

    return (mx1 == INT_MIN) ? 0 : mx1;
}

int solve(vector<int> &A) {
    int nA = A.size();
    vector<vector<int>> adjList(nA, vector<int>());
    int u, v;
    int root;
    for (u = 0; u < nA; u++) {
        v = A[u];
        if (v != -1) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } else {
            root = u;
        }
    }
    int ans = INT_MIN;
    vector<bool> visited(nA);

    dfs(adjList, visited, root, ans);

    return ans == INT_MIN ? 0 : ans;
}