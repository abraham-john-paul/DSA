using pii = pair<int, int>;

void dfs(vector<vector<pii>>& adjList, vector<int>& visited, 
    vector<int>& wgtTillNow,
    int curWgt, int& ans, int node, int parent) {
    visited[node] = 1;
    wgtTillNow[node] = curWgt;
    int v, wgt;
    sort(adjList[node].begin(), adjList[node].end());
    for (const auto& neigh : adjList[node]) {
        tie(wgt, v) = neigh;
        if (!visited[v]) {
            // cout << node << "->" << v << endl;
            dfs(adjList, visited, wgtTillNow, curWgt + wgt, ans, v, node);
        } else if (v != parent && visited[v] != 2) {
            ans = min(ans, curWgt + wgt - wgtTillNow[v]);
            // cout << node << " " << v << " " << ans <<  "\n";
        }
    }
    visited[node] = 2;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<pii>> adjList(A + 1);
    int u, v, wgt;
    for (const auto& e : B) {
        u = e[0];
        v = e[1];
        wgt = e[2];
        adjList[u].push_back({wgt, v});
        if (u == v) continue;
        adjList[v].push_back({wgt, u});
    }
    vector<int> visited(A + 1);
    vector<int> wgtTillNow(A + 1);
    int ans = INT_MAX;
    for (u = 1; u <= A; u++) {
        if (visited[u] == 0) {
            dfs(adjList, visited, wgtTillNow, 0, ans, u, -1);
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
