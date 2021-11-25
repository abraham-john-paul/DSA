#include "../header.h"

#define m int(1e9 + 7)

#include <numeric>

int fastPower(long long a, int p) {
    long long ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans = (ans * a) % m;
        }
        p >>= 1;
        a = (a * a) % m;
    }

    return ans;
}

void dfs(vector<unordered_set<int>>& adjList, vector<bool>& visited, int u) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            dfs(adjList, visited, v);
        }
    }
}

int findRoot(int node, vector<int>& root) {
    if (root[node] == node) {
        return node;
    }
    root[node] = findRoot(root[node], root);
    return root[node];
}

void makeUnion(int node1, int node2, vector<int>& root, int& nGrps) {
    int r1 = findRoot(node1, root);
    int r2 = findRoot(node2, root);
    if (r1 == r2) {
        return;
    }
    root[r1] = r2;
    nGrps--;
}

int solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    vector<int> root(A + 1);
    iota(root.begin(), root.end(), 0);
    int nGrps = A;
    unordered_set<int> walkers;
    int u, v;
    for (const auto& e : B) {
        u = e[0];
        v = e[1];
        makeUnion(u, v, root, nGrps);
        walkers.insert(u);
        walkers.insert(v);
    }
    for (const auto& e : C) {
        u = e[0];
        v = e[1];
        auto itr1 = walkers.find(u);
        auto itr2 = walkers.find(v);
        auto endItr = walkers.end();
        if (!(itr1 == endItr && itr2 == endItr) && (itr1 == endItr || itr2 == endItr)) {
            return 0;
        }
        makeUnion(u, v, root, nGrps);
    }

    return fastPower(2, nGrps);
}