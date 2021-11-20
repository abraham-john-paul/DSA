#include "../header.h"

using pii = pair<int, int>;
using minPairPQ = priority_queue<pii, vector<pii>, greater<pii>>;

vector<int> solve(int A, vector<vector<int> > &B, int C) {
    vector<int> distance(A, -1);
    vector<vector<pii>> adjList(A, vector<pii>());
    minPairPQ pq;
    pq.push(make_pair(0, C));
    int u, v, dist;
    for (const auto& e : B) {
        u = e[0];
        v = e[1];
        dist = e[2];
        adjList[u].push_back(make_pair(dist, v));
        adjList[v].push_back(make_pair(dist, u));
    }
    
    while(!pq.empty()) {
        auto& p = pq.top();
        dist = p.first;
        u = p.second;
        if (distance[u] == -1) {
            distance[u] = dist;
        }
        pq.pop();

        for (auto& neigh :  adjList[u]) {
            if (distance[neigh.second] == -1) {
                pq.push(make_pair(neigh.first + distance[u], neigh.second));
            }
        }
    }

    return distance;
}
