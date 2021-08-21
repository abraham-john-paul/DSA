#include "../header.h"

int binarySearch(const vector<int>& A, int B, int start, int end) {
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid] == B) {
            return mid;
        } else  if (A[mid] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int search(const vector<int> &A, int B) {
    const int last = A.back();
    const int nA = A.size() - 1;
    if (B == last) {
        return nA - 1;
    }
    int start = 0;
    int end = nA - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > last) {
            start = mid + 1;
        } else if (A[mid] < last) {
            end = mid - 1;
        }
    }

    int ans = -1; 
    if (B < nA) {
        ans = binarySearch(A, B, mid, nA - 1);
    } else {
        ans = binarySearch(A, B, 0, mid - 1);
    }

    return ans;
}