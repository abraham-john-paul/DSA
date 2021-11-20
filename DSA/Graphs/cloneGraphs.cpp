#include "../header.h"

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
        return node;
    }
    using puu = pair<UndirectedGraphNode*, UndirectedGraphNode*>;
    queue<puu> q;
    auto* src = new UndirectedGraphNode(node->label);
    q.push(make_pair(node, src));
    unordered_set<UndirectedGraphNode*> visited;
    visited.insert(node);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
    nodeMap.insert(make_pair(node, src));
    while (!q.empty()) {
        auto& p = q.front();

        for (auto* neigh : p.first->neighbors) {
            if (visited.find(neigh) == visited.end()) {
                visited.insert(neigh);
                auto* next = new UndirectedGraphNode(neigh->label);
                nodeMap.insert(make_pair(neigh, next));
                p.second->neighbors.push_back(next);
                q.push(make_pair(neigh, next));
            } else {
                p.second->neighbors.push_back(nodeMap[neigh]);
            }
        }

        q.pop();
    }

    return src;
}
