#include "../header.h"

vector<int> slidingMaximum(const vector<int> &A, int B) {
    int i = 0;
    const int nA = A.size();
    deque<int> dq;
    while (i < B) {
        while (!dq.empty() && A[dq.back()] < A[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        i++;
    }
    vector<int> ans(nA - B + 1);
    int j = 0;
    int idx;
    for (; i < nA - B; i++) {
        idx = dq.front();
        ans[j++] = A[idx];
        if (i - B == idx) {
            dq.pop_front();
        }
        while (!dq.empty() && A[dq.back()] < A[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return ans;
}