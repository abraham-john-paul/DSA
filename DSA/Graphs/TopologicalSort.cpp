// void dfs(const vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& ans, int u) {
//     visited[u] = true;
//     for (int v : adjList[u]) {
//         if(!visited[v]) {
//             dfs(adjList, visited, ans, v);
//         }
//         ans.push_back(v);
//     }
// }

// vector<int> Solution::solve(int A, vector<vector<int> > &B) {
//     vector<vector<int>> adjList(A + 1, vector<int>());
//     for (const auto& e : B) {
//         adjList[e[0]].push_back(e[1]);
//     }
//     vector<int> ans;
//     vector<bool> visited(A + 1, false);
//     for (int i = 1; i <= A; i++) {
//         if (!visited[i]) {
//             dfs(adjList, visited, ans, i);
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> inDeg(A, 0);
    vector<vector<int>> adjList(A + 1, vector<int>());
    for (const auto& e : B) {
        adjList[e[0]].push_back(e[1]);
        inDeg[e[1]]++;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=A;i++) {
        if (inDeg[i] == 0)
            pq.push(i);
    }
    vector<int>ans;
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for(int v : adjList[u])
        {
            inDeg[v]--;
            if (inDeg[v] == 0)
                pq.push(v);
        }
    }
    // if(ans.size()!=A)ans.clear();
    return ans;
}