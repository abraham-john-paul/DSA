#include <bits/stdc++.h>

using namespace std;

vector<int> flip(string A) {
    int n = A.size();
    const int nOnes = count(A.begin(), A.end(), '1');
    int curMaxOnes = 0;
    int maxOnes = nOnes;
    int start = -1;
    pair<int, int> p = {0, -1};

    for (int i = 0; i < n; i++) {
        switch (A[i]) {
            case '1':
                curMaxOnes -= 1;
            break;
            case '0':
                if (curMaxOnes == 0 && start == -1) {
                    start = i;
                }
                curMaxOnes += 1;
            break;       
        }
        if (curMaxOnes < 0) {
            start = -1;
            curMaxOnes = 0;
        }
        if (maxOnes < nOnes + curMaxOnes) {
            maxOnes = nOnes + curMaxOnes;
            p = {start, i};
        } else if (maxOnes == nOnes + curMaxOnes && p.second != -1) {
            int s1 = p.first;
            int s2 = start;
            pair<int, int> p_ = {start, i};
            if (p > p_) {
                p = p_;
            }
        }
    }

    if (p.second == -1) {
        return {};
    }

    return p.second == -1 ? vector<int>() : vector<int>({p.first + 1, p.second + 1});
}