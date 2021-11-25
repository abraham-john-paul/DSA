#include "../header.h"

vector<vector<int> > solve(vector<vector<int> > &A) {
    int i, j, k;
    const int nRow = A.size();
    const int nCol = A[0].size();
    
    for (int node = 0; node < nRow; node++) {
        for (i = 0; i < nRow; i++) {
            for (j = 0; j < nCol; j++) {
                if (i == node || j == node || i == j) continue;

                if (A[node][j] != -1 && A[i][node] != -1) {
                    if (A[i][j] == -1) {
                        A[i][j] = A[i][node] + A[node][j];
                    } else {
                       A[i][j] = min(A[i][j], A[i][node] + A[node][j]);
                    }
                }
            }
        }
    }

    return A;
}
