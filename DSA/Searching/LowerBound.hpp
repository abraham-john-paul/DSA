#include "../header.h"

int lowerBound(const vector<int>& A, int B) {
    int start = 0; 
    int mid;
    int end = A.size() - 1;
    int ans = A.size();
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (A[mid] == B) {
            ans = mid;
            end = mid - 1;
        } else if (A[mid] < B) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}