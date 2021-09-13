#include "../header.h"

#define ll long long
int m = 1e9 + 7;

ll aggregateWindowValue(const vector<int>& A, const int B, function<bool(int, int)> pred) {
    deque<int> dq;
    int i;
    for (i = 0; i < B; i++) {
        while (!dq.empty() && pred(A[dq.back()], A[i])) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    const int nA = A.size();
    ll ans = A[dq.front()];
    
    for (; i < nA; i++) {
        if (dq.front() <= (i - B)) {
            dq.pop_front(); 
        }

        while((!dq.empty()) && pred(A[dq.back()], A[i])) {
            dq.pop_back();
        }

        dq.push_back(i); 
        ans += A[dq.front()];
    }
    
    return ans;
}

int solve(vector<int> &A, int B) {
    ll ans = 0;
    ans = (ans + aggregateWindowValue(A, B, greater_equal<int>()) + m) % m;
    ans = (ans + aggregateWindowValue(A, B, less_equal<int>()) + m) % m;
    return ans; 
}