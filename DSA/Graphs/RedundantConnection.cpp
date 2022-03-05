#include "header.h"

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int nNodes = edges.size();
        unordered_map<int, int> parentOf;
        parentOf.reserve(nNodes);
        
        unordered_set<int> visited;
        vector<int> cycle;
        int src, dest;
        int parent1 = 0, parent2 = 0, child = 0;
        for (const auto& edge : edges) {
            src = edge[0];
            dest = edge[1];
            if (visited.find(src) != visited.end() &&
                visited.find(dest) != visited.end()) {
                cycle = {src, dest};
            } else {
                visited.insert(src);
                visited.insert(dest);
            }
            
            if (parentOf.find(dest) != parentOf.end()) {
                parent1 = parentOf[dest];
                parent2 = src;
                child = dest;
            } else {
                parentOf[dest] = src;
            }
        }
        
        //  No node with 2 parents exist
        if (child == 0) {
            return cycle;
        } else {
            // check if parent1 is part of the cycle
            while (parentOf.find(parent1) != parentOf.end() && 
                   parent1 != child) {
                parent1 = parentOf[parent1];
            }
        }
        
        return parent1 == child ? vector<int>({parentOf[child], child}) : 
            vector<int>({parent2, child});
    }
};