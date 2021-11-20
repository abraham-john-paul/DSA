#include "../header.h"

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	int findRoot(int node, vector<int>& root) {
	    if (node == root[node]) {
	        return node;
	    }
	    
	    root[node] = findRoot(root[node], root);
	    return root[node];
	}
	
	bool unionOfTrees(int node1, int node2, vector<int>& root, vector<int>& rank) {
	    int r1 = findRoot(node1, root);
	    int r2 = findRoot(node2, root);
	    if (r1 == r2) {
	        return false;
	    }
	    if (rank[r1] > rank[r2]) {
	        root[r2] = r1;
	    } else if(rank[r2] > rank[r1]) {
	        root[r1] = r2;
	    } else {
	        root[r2] = r1;
	        rank[r1]++;
	    }
	    return true;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        using pii = pair<int, int>;
        using pip = pair<int, pii>;
        vector<pip> edges;
        vector<int> root(V, -1);
        vector<int> rank(V, 0);
        
        for (int i = 0; i < V; i++) {
            for (auto& e: adj[i]) {
                    root[i] = i;
                    root[e[0]] = e[0];
                    edges.push_back({e[1], {i, e[0]}});
            }
        }
        
        sort(edges.begin(), edges.end());
        int ans = 0;
        int u, v, wgt;
        for (const auto& e : edges) {
            wgt = e.first;
            tie(u, v) = e.second;
            if (unionOfTrees(u, v, root, rank)) {
                ans += wgt;
            }
        }
        
        return ans;
    }
};