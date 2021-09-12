#include "../header.h"

#define m  (int)(1e9 + 7)
#define ll long long

int aggregateWindowValue(const vector<int>& A, const int B, function<bool(int, int)> pred) {
    deque<int> dq;
    int i;
    for (i = 0; i < B; i++) {
        while (!dq.empty() && pred(A[dq.back()], A[i])) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    const int nA = A.size();
    ll ans = 0;
    ans = (ans + A[dq.front()]) % m;
    
    for (; i < nA; i++) {
        if (i - B > dq.front()) {
            dq.pop_front();
        }
        
        while (!dq.empty() && pred(A[dq.back()], A[i])) {
            dq.pop_back();
        }
        dq.push_back(i);
        ans = (ans + A[dq.front()]) % m;
        
    }

    return ans;
}

int solve(vector<int> &A, int B) {
    ll ans = 0;
    
    ans = (ans + aggregateWindowValue(A, B, less<int>())) % m;
    ans = (ans + aggregateWindowValue(A, B, greater<int>())) % m;

    return ans;
}
