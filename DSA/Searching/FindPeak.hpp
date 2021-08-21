#include "../header.h"

int solve(vector<int> &A) {
    const int nA = A.size();
    if (nA == 1) {
        return A[0];
    } 
    if (nA > 1) {
        if (A.front() > A[1]) {
            return A.front();
        } else if (A.back() > A[nA - 2]) {
            return A.back();
        }
    }
    int start = 0;
    int end = nA - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid - 1] <= A[mid]) {
            if (A[mid] >= A[mid + 1]) {
                return A[mid];
            } else {
                start = mid + 1;
            }
        } else {
            if (A[mid] > A[mid + 1]) {
                end = mid - 1;
            }
        }
    }
}