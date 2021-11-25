#include "../header.h"

#include <numeric>

int findRoot(int node, vector<int>& root) {
    if (root[node] == node) {
        return node;
    }
    root[node] = findRoot(root[node], root);
    return root[node];
}

bool makeUnion(int node1, int node2, vector<int>& root, vector<int>& rank) {
    int root1 = findRoot(node1, root);
    int root2 = findRoot(node2, root);
    if (root1 == root2) {
        return false;
    }

    if (rank[root1] > rank[root2]) {
        root[root2] = root1;
    } else  {
        root[root1] = root2;
        if (rank[root1] == rank[root2]) {
            rank[root2]++;
        }
    }

    return true; 
}

int primsAlgo(int A, vector<vector<int> > &B) {
    vector<int> dist(A + 1, INT_MAX);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<pii>> adjList(A + 1, vector<pii>());
    int u, v, cost;
    for (auto& e : B) {
        u = e[0];
        v = e[1];
        cost = e[2];
        adjList[u].push_back({cost, v});
        adjList[v].push_back({cost, u});
    }

    int ans = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        tie(cost, u) = pq.top();
        pq.pop();
        if (dist[u] == INT_MAX) {
            dist[u] = cost;
            ans += cost;
        }
        
        for (auto& p : adjList[u]) {
            v = p.second;
            if (dist[v] == INT_MAX) {
                pq.push(p);
            }
        }
    }

    return ans;
}

struct Edge {
    int u;
    int v;
    int wgt;
};

int kruskalsAlgo(int A, vector<vector<int> > &B) {
    vector<int> root(A + 1);
    iota(root.begin(), root.end(), 0);

    vector<int> rank(A + 1, 1);

    vector<Edge> edges;
    for (auto& e : B) {
        edges.push_back({e[0], e[1], e[2]});
    }

    sort(edges.begin(), edges.end(), [](auto& e1, auto& e2) {
        return e1.wgt <= e2.wgt;
    });
    int u, v, wgt;
    int ans = 0;
    for (auto& e : edges) {
        u = e.u;
        v = e.v;
        wgt = e.wgt;
        if (makeUnion(u, v, root, rank)) {
            ans += wgt;
        }
    }

    return ans;
}

int solve(int A, vector<vector<int> > &B) {
    return kruskalsAlgo(A, B);
}