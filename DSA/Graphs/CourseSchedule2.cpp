#include "header.h"

enum class NodeState {
    IN_PROGRESS,
    VISITED,
};

class Solution {
public:
    bool dfs(const vector<vector<int>>& adjList, unordered_map<int, NodeState>& visited,
        vector<int>& ans, int node) {
            visited[node] = NodeState::IN_PROGRESS;
            
            for (int dest : adjList[node]) {
                if (visited.find(dest) == visited.end()) {
                    if (!dfs(adjList, visited, ans, dest)) {
                        return false;
                    }
                } else if (visited[dest] == NodeState::IN_PROGRESS) {
                    return false;
                }
            }
        
            visited[node] = NodeState::VISITED;
            ans.push_back(node);
            
            return true;
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, NodeState> visited;
        visited.reserve(numCourses);
        
        vector<vector<int>> adjList(numCourses);
        int u, v;
        
        for (const auto& edge : prerequisites) {
            u = edge[0];
            v = edge[1]; 
            adjList[u].push_back(v);
        }

        vector<int> ans;
        ans.reserve(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (visited.find(i) == visited.end() &&
                    !dfs(adjList, visited, ans, i)) {
                return {};
            }
        }

        return ans;
    }
};