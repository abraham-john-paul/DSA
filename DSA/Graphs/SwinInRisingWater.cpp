#include "header.h"

class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n));
                
        using pii = pair<int, int>;
        const vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        using pip = pair<int, pii>;
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        int time, r, c;
        int dr, dc;
        pii node;
        
        while (!pq.empty()) {
            tie(time, node) = pq.top();
            tie(r, c) = node;
            
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            pq.pop();
            
            if (!visited[r][c]) {
                visited[r][c] = true;

                for (const auto& d : directions) {
                    tie(dr, dc) = d;
                    dr += r;
                    dc += c;
                    if (isValid(dr, dc, n) && !visited[dr][dc])  {
                        pq.push({max(time, grid[dr][dc]), {dr, dc}});
                    }
                }
            }
        }
        
        return 0;
    }
};