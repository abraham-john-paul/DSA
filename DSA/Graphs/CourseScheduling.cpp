#include "header.h"

enum class NodeState {
    UNVISITED,
    IN_PROGRESS,
    VISITED,
};

class Solution {
public:
    bool isAcyclic(const vector<vector<int>>& adjList, vector<NodeState>& state, int node) {
        state[node] = NodeState::IN_PROGRESS;
        for (int neighbour : adjList[node]) {
            switch (state[neighbour]) {
                case NodeState::UNVISITED:
                    if (isAcyclic(adjList, state, neighbour) == false) {
                        return false;
                    }
                    break;
                case NodeState::IN_PROGRESS:
                        return false;
                    break;
                case NodeState::VISITED:
                    continue;
            }
        }

        state[node] = NodeState::VISITED;

        return true;
    }   
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses);
        vector<vector<int>> adjList(numCourses);
        int u, v;
        for (const auto& p : prerequisites) {
            u = p[0];
            v = p[1];
            adjList[v].push_back(u);
            // inDeg[u]++;
        }
        
        vector<NodeState> state(numCourses, NodeState::UNVISITED);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == NodeState::UNVISITED && isAcyclic(adjList, state, i) == false) {
                return false;
            }
        }
        
        return true;
    }
//         queue<int> q;
//         for (int i = 0; i < numCourses; ++i) {
//             if (inDeg[i] == 0) {
//                 q.push(i);
//             }
//         }
//         int courseTaken = 0;
//         // vector<bool> visited(numCourses);
//         while (!q.empty()) {
//             u = q.front();
//             q.pop();
//             courseTaken++;
//             // visited[u] = true;
//             for (int v : adjList[u]) {
//                 inDeg[v]--;
//                 if (inDeg[v] == 0) {
//                     q.push(v);
//                 }
//             }
//         }
        
//         return courseTaken == numCourses;
//     }
};