#include "../header.h"

void solve(int row, const int N, vector<int>& queenPlacements, 
    unordered_set<int>& visitedCol,
    unordered_set<int>& visitedLDiag,
    unordered_set<int>& visitedRDiag,
    vector<vector<string>>& ans) {
    if (row == N) {
        vector<string> curPlacement(N, string(N, '.'));
        int c;
        for (int r = 0; r < N; r++) {
            c = queenPlacements[r];
            curPlacement[r][c] = 'Q';
        }
        ans.push_back(curPlacement);
        return;
    }
    int lDiag, rDiag;
    for (int col = 0; col < N; col++) {
        lDiag = row + col;      
        rDiag = row - col;
        if (visitedCol.find(col) == visitedCol.end() &&
            visitedLDiag.find(lDiag) == visitedLDiag.end() &&
            visitedRDiag.find(rDiag) == visitedRDiag.end()) {
                // Do
                visitedCol.insert(col);
                visitedLDiag.insert(lDiag);
                visitedRDiag.insert(rDiag);
                queenPlacements.push_back(col);
                // Call
                solve(row + 1, N, queenPlacements, 
                    visitedCol, visitedLDiag, visitedRDiag, ans);
                // Undo
                queenPlacements.pop_back();
                visitedCol.erase(col);
                visitedLDiag.erase(lDiag);
                visitedRDiag.erase(rDiag);
            } 
    }

}

vector<vector<string>> solveNQueens(int A) {
    vector<vector<string>> ans;
    vector<int> queenPlacements;
    queenPlacements.reserve(A);

    unordered_set<int> visitedCol;
    unordered_set<int> visitedLDiag;
    unordered_set<int> visitedRDiag;

    solve(0, A, queenPlacements,
        visitedCol, visitedLDiag, visitedRDiag, ans);
    
    return ans;
}