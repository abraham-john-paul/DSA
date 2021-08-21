#include "../header.h"

bool binaryRowSearch(const vector<vector<int> > &A, const int B, int row, int start, int end) {
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[row][mid] == B) {
            return true;
        } else if (A[row][mid] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}

int lowerBoundRow(const vector<vector<int> > &A, const int B) {
    int start = 0;
    int end = A.size();
    int mid;
    int nCol = A[0].size();
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid][nCol - 1] >= B) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int searchMatrix(vector<vector<int> > &A, int B) {
    int found = 0;

    int nRow = A.size();
    int nCol = A[0].size();
    int c = lower_bound(A[nRow -1].begin(), A[nRow - 1].end(), B) - A[nRow - 1].begin();
    int r = lowerBoundRow(A, B);

    while (r < nRow) {
        if (A[r][c] > B) {
            break;
        }
        binaryRowSearch(A, B, r, c, nCol - 1);
        r++;
    }

    return found;
}