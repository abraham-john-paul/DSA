#include "../header.h"

int Solution::solve(string A, int B) {
    int end = 0;
    int nOps = 0;
    int ans = 0;
    int nA = A.size();
    queue<int> q;
    
    for (int i = 0; i < nA; i++) {
        if (!q.empty() && q.front() == i) {
            q.pop();
            nOps--;
        }
        switch (A[i]) {
            case '1': 
                if (nOps & 1) {
                    ans++;
                    nOps++;
                    end = i + B;
                    q.push(end);
                }
                break;
            case '0':
                if ((nOps & 1) == 0) {
                    ans++;
                    nOps++;
                    end = i + B;
                    q.push(end);
                }
                break;
        }
        if (end > nA) {
            return -1;
        }
    }

    return ans;