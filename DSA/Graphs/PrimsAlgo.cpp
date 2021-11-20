#include "../header.h"
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> mnpq;
        mnpq.push({0, 0});
        int ans = 0;
        vector<int> dist(V, -1);
        int u;
        while (!mnpq.empty()) {
            auto p = mnpq.top();
            mnpq.pop();
            u = p.second;
            if (dist[u] == -1) {
                dist[u] = p.first;
                ans += p.first;
                
                for (const auto& v : adj[u]) {
                    if (dist[v[0]] == -1) {
                        mnpq.push({v[1], v[0]});
                    }
                }
            }
        }
        
        return ans;
    }
};