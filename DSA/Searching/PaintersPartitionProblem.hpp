#include "../header.h"

bool validate(int A, int B, vector<int> &C, long long max) {
    int nPainters = 1;
    long long pLen = 0;
    
    for (long long len : C) {
        if ((pLen + len) > max) {
            nPainters++;
            pLen = len;
            if (nPainters > A) {
                return false;
            }
        } else {
            pLen += len;
        }
    }
    
    return nPainters <= A;
}

int paint(int A, int B, vector<int> &C) {
    const int m = 10000003;
    long long totalLen = 0;
    long long maxLen = INT_MIN;
    for (long long len : C) {
        maxLen = max(maxLen, len);
        totalLen += len;
    }

    long long start = maxLen;
    long long end = totalLen;
    long long mid;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (validate(A, B, C, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return ((end + 1) * B) % m;
}
