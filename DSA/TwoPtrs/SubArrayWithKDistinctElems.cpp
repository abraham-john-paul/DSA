#include "../header.h"

int findAtmostBDistinctElementSubarrays(const vector<int>& A, int B) {
    int lo = 0;
    int hi = 0;
    const int nA = A.size();
    int cnt = 0;

    unordered_map<int, int> freqMap;

    while (hi < nA) {
        freqMap[A[hi]]++;
        hi++;

        while (freqMap.size() > B) {
            if (freqMap[A[lo]] == 1) {
                freqMap.erase(A[lo]);
            } else {
                freqMap[A[lo]]--;
            }
            lo++;
        }
        if (freqMap.size() <= B) {
            cnt += (hi - lo);
        }
    }

    return cnt;
}

int Solution::solve(vector<int> &A, int B) {
    return findAtmostBDistinctElementSubarrays(A, B) - findAtmostBDistinctElementSubarrays(A, B - 1);
}