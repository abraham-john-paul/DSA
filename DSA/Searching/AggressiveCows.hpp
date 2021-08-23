#include "../header.h"

bool validateCowPlacement(const vector<int>& A, int nCows, int dist) {
    int cowsPlaced = 0;
    auto itr = A.begin();
    while (itr != A.end() && cowsPlaced < nCows) {
        cowsPlaced++;
        itr = lower_bound(itr + 1, A.end(), *itr + dist);
    }

    return cowsPlaced == nCows;
}

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    const int nA = A.size();
    int minStall = A[0];
    int maxStall = A[0];
    int minDiff = A[0];
    for (int i = 1; i < nA; i++) {
        minDiff = min(A[i] - A[i - 1], minDiff);
        minStall = min(minStall, A[i]);
        maxStall = max(maxStall, A[i]);
    }
    
    int start = minDiff;
    int end = (maxStall - minStall) / (B - 1);
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (validateCowPlacement(A, B, mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start - 1;
}