#include "header.h"

class Solution {
    int nRow = 0, nCol = 0;

    using pii = pair<int, int>;
    const vector<pii> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValidCell(int r, int c) const {
        return r >= 0 && r < nRow && c >= 0 && c < nCol;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        nRow = grid.size(), nCol = grid[0].size();
        int perimeter = 0;
        int nr, nc;
        
        for (int r = 0; r < nRow; ++r) {
            for (int c = 0; c < nCol; ++c) {
                
                if (grid[r][c] == 0) continue; // Skip water cell
                
                perimeter += 4;
                
                for (const auto& d : directions) {
                    tie(nr, nc) = d;
                    nr += r;
                    nc += c;
                    
                    if (!isValidCell(nr, nc) || grid[nr][nc] == 0) continue;
                    
                    perimeter -= 1;
                }
            }
        }
        
        return perimeter;
    }
};