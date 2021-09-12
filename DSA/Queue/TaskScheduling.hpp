#include "../header.h"

int solve(vector<int> &A, vector<int> &B) {
    queue<int> q;
    for (const int a : A) {
        q.push(a);
    }
    
    int b = 0;
    const int nB = B.size();
    int ans = 0;
    int task;
    while (!q.empty()) {
        task = q.front();
        q.pop();
        if (task == B[b]) {
            b++;
        } else {
            q.push(task);
        }
        ans++;
    }
    
    return ans;
}
