#include <bits/stdc++.h>

using namespace std;

vector<int> flip(string A) {
    int n = A.size();
    const int nOnes = count(A.begin(), A.end(), '1');
    int curMaxOnes = 0;
    int maxOnes = nOnes;
    int start;
    pair<int, int> p = {0, -1};

    for (int i = 0; i < n; i++) {
        switch (A[i]) {
            case '1':
                curMaxOnes -= 1;
            break;
            case '0':
                if (curMaxOnes == 0) {
                    start = i;
                }
                curMaxOnes += 1;
            break;       
        }
        if (curMaxOnes < 0) {
            curMaxOnes = 0;
        }

        if (maxOnes < nOnes + curMaxOnes) {
            maxOnes = nOnes + curMaxOnes;
            p = {start, i};
        } else if (maxOnes == nOnes + curMaxOnes) {
            int s1 = p.first;
            int s2 = start;

            for (int j = 0; j <= i; j++) {
                if (A[i] < A[j]) {
                    break;
                } else if (A[i] > A[j]) {
                    p = {start, i};
                    break;
                }
            }
        }
    }

    if (p.second == -1) {
        return {};
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i >= p.first && i <= p.second) {
            if (A[i] == '0') {
                ans[i] = 1;
            }
        } else {
            if (A[i] == '1') {
                ans[i] = 1;
            } 
        }
    }
    return ans;
}