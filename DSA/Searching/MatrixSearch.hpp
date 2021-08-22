#include "../header.h"

int searchMatrix(vector<vector<int> > &A, int B) {
    int nRow = A.size();
    int nCol = A[0].size();
    int r, c;
    int start = 0;
    int end = nRow * nCol - 1;
    int mid;
    
    int ans = 0;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        r = mid / nCol;
        c = mid % nCol;
        if (A[r][c] == B) {
            ans = 1;
            break;
        } else if (A[r][c] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}