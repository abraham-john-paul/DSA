#include "../header.h"

int Solution::solve(vector<int> &A) {
    using ll = long long;
    priority_queue<ll> mxpq;
    priority_queue<ll, vector<ll>, greater<ll>> mnpq;
    const int nA = A.size();
    ll median;
    ll a, b;
    bool isEven = false;
    
    for (int i = 0; i < nA; i++) {
        mxpq.push(A[i]);
        if (mxpq.size() - mnpq.size() > 1) {
            mnpq.push(mxpq.top());
            mxpq.pop();
        } else {
            if (!mnpq.empty() && (mxpq.top() > mnpq.top())) {
                a = mxpq.top();
                mxpq.pop();
                b = mnpq.top();
                mnpq.pop();
                mnpq.push(a);
                mxpq.push(b);
            }
        }
        isEven = !((mnpq.size() + mxpq.size()) & 1);
        median = (!isEven) ? mxpq.top() : (mxpq.top() + mnpq.top());
        if ((i + 1) < nA) {
            if ((isEven && (median == ((ll)2 * A[i + 1]))) || (!isEven && median == A[i + 1])) {
            return 1;
            }
        }
    }
    while (!mnpq.empty()) {
        mnpq.pop();
    }
    while (!mxpq.empty()) {
        mxpq.pop();
    }
    for (int i = nA - 1; i >= 0; i--) {
        mxpq.push(A[i]);
        if (mxpq.size() - mnpq.size() > 1) {
            mnpq.push(mxpq.top());
            mxpq.pop();
        } else {
            if (!mnpq.empty() && (mxpq.top() > mnpq.top())) {
                a = mxpq.top();
                mxpq.pop();
                b = mnpq.top();
                mnpq.pop();
                mnpq.push(a);
                mxpq.push(b);
            }
        }
        isEven = !((mnpq.size() + mxpq.size()) & 1);
        median = (!isEven) ? mxpq.top() : (mxpq.top() + mnpq.top());
        if ((i - 1) >= 0) {
            if ((isEven && (median == ((ll)2 * A[i - 1]))) || (!isEven && median == A[i - 1])) {
            return 1;
            }
        }
    }
    
    return 0;
}