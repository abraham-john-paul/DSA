#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A) {
    using ll = long long;
    ll ans = 0;
    ll maxSumTillNow = 0;
    const int n = A.size();
    int start = 0;
    pair<int, int> p {0, -1};

    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            maxSumTillNow = 0;
            start = i + 1;
            continue;
        }

        if (A[i] <= maxSumTillNow  + A[i]) {
            maxSumTillNow = maxSumTillNow + A[i];
        } else {
            maxSumTillNow = A[i];
            start = i;
        }

        if (ans < maxSumTillNow) {
            ans = maxSumTillNow;
            p = {start, i};
        } else if (ans == maxSumTillNow) {
            if (p.second - p.first + 1 < i - start + 1) {
                p = {start, i};
            } else if (p.second - p.first + 1 == i - start + 1) {
                int s1 = p.first;
                int s2 = start;
                int isCurBigger = false;
                for (int j = 0; j < i; j++, s1++, s2++) {
                    if (A[s1] > A[s2]) {
                        isCurBigger = true;
                        break;
                    } else if (A[s1] < A[s2]){
                        break;
                    }
                }
                if (isCurBigger) {
                    p = {start, i};
                }
            }
        }
    }
     
    return (p.second == -1) ? vector<int> {} : vector<int>(A.begin() + p.first, A.begin() + p.second + 1);
}