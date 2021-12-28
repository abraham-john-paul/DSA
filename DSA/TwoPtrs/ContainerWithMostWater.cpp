#include "../header.h"

int Solution::maxArea(vector<int> &A) {
    const int nA = A.size();
    int ans = 0;
    int h;
    int lo = 0;
    int hi = nA - 1;

    while (lo < hi) {
        h = min(A[lo], A[hi]);
        ans = max(ans, h * (hi - lo));
        if (h == A[lo]) {
            lo++;
        } else {
            hi--;
        }
    }


    return ans;
}
