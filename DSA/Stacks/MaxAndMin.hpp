#include "../header.h"

void prevMinLeft(vector<int>& minLeft, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = 0; i < nA; i++) {
        while (!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        minLeft[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
}

void prevMaxLeft(vector<int>& maxLeft, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = 0; i < nA; i++) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            stk.pop();
        }
        maxLeft[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
}

void prevMinRight(vector<int>& minRight, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = nA - 1; i >= 0; i--) {
        while (!stk.empty() && A[stk.top()] >= A[i]) {
            stk.pop();
        }
        minRight[i] = stk.empty() ? nA : stk.top();
        stk.push(i);
    }
}

void prevMaxRight(vector<int>& maxRight, const vector<int>& A) {
    stack<int> stk;
    const int nA = A.size();
    for (int i = nA - 1; i >= 0; i--) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            stk.pop();
        }
        maxRight[i] = stk.empty() ? nA : stk.top();
        stk.push(i);
    }
}

int solve(vector<int> &A) {
    const int nA = A.size();
    
    vector<int> minLeft(nA);
    prevMinLeft(minLeft, A);
    
    vector<int> maxLeft(nA);
    prevMaxLeft(maxLeft, A);
    
    vector<int> minRight(nA);
    prevMinRight(minRight, A);

    vector<int> maxRight(nA);
    prevMaxRight(maxRight, A);

    long long ans = 0;
    const int m = 1000000007;
    long long minCountLeft, minCountRight, maxCountLeft, maxCountRight;
    int i, j;
    for (i = 0; i < nA; i++) {
        j = minLeft[i];
        minCountLeft = i - j;

        j = minRight[i];
        minCountRight = j - i;

        j = maxLeft[i];
        maxCountLeft = i - j;

        j = maxRight[i];
        maxCountRight = j - i;
        
        ans = (ans  + (A[i] * (maxCountLeft * maxCountRight) % m) + m) % m;
        ans = (ans - (A[i] * (minCountLeft * minCountRight) % m) + m) % m;
    }

    return ans;
}
