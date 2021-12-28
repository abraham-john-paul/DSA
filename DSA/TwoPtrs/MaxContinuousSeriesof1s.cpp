#include "../header.h"

vector<int> Solution::maxone(vector<int> &A, int B) {
    int start;
    int cnt = 0;
    int lo = 0;
    int hi = -1;
    const int nA = A.size();

    while (hi < nA) {
        hi++;
        if (A[hi] == 0) {
            B--;
            while (B < 0) {
                if (A[lo] == 0) {
                    B++;
                }
                lo++;
            }
        }
        if (hi < nA && (hi - lo + 1) > cnt) {
            start = lo;
            cnt = hi - lo + 1;
        }
    }

    vector<int> ans(cnt);
    iota(ans.begin(), ans.end(), start);
    return ans;
}
