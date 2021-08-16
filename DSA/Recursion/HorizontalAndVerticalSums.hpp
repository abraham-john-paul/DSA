#include "../header.h"

void backtrack(bool& ans, int& A, vector<vector<int> > &B, const int C) {
    if (A < 0 || ans) {
        return;
    }
    const int nRow = B.size();
    const int nCol = B[0].size();
    int sum;
    ans = true;
    for (int r = 0; r < nRow; r++) {
        for (int c1 = 0; c1 < nCol; c1++) {
            sum = 0;
            for (int c2 = c1; c2 < nCol; c2 ++) {
                sum += B[r][c2];
                if (sum > C) {
                    ans = false;
                    for (int i = c1; i <= c2; i++) {
                        B[r][i] = -B[r][i];
                        A--;
                        backtrack(ans, A, B, C);
                        A++;
                        B[r][i] = -B[r][i];
                    }
                    return;
                }
            }
        }
    }

    for (int c = 0; c < nCol; c++) {
        for (int r1 = 0; r1 < nRow; r1++) {
            sum = 0;
            for (int r2 = r1; r2 < nRow; r2 ++) {
                sum += B[r2][c];
                if (sum > C) {
                    ans = false;
                    for (int i = r1; i <= r2; i++) {
                        B[i][c] = -B[i][c];
                        A--;
                        backtrack(ans, A, B, C);
                        A++;
                        B[i][c] = -B[i][c];
                    }
                    return;
                }
            }
        }
    }
}

int solve(int A, vector<vector<int> > &B, int C) {
    bool ans = false;
    int rowSum = 0;
    int colSum = 0;
    
    backtrack(ans, A, B, C);
    
    return ans ? 1 : 0;
}