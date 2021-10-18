#include "../header.h"

#define m int(1e9 + 7)
#define ll long long

void buildSegTree(vector<int>& segTree, int idx, int start, int end, const vector<int>& A) {
    if (start == end) {
        segTree[idx] = A[start];
    } else {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        buildSegTree(segTree, left, start, mid, A);
        buildSegTree(segTree, right, mid + 1, end, A);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

void updateSegTree(vector<int>& segTree, int idx, int start, int end, const int i, const int val) {
    if (i < start || i > end) {
        return;
    }
    if (start == end){
        segTree[idx] = val;
    } else {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        updateSegTree(segTree, left, start, mid, i, val);
        updateSegTree(segTree, right, mid + 1, end, i, val);
        segTree[idx] = segTree[left] + segTree[right]; 
    }
}

ll querySegTree(vector<int>& segTree, int idx, int start, int end, const int L, const int R, ll& wgt) {
    if (end < L || R < start) {
        return 0;
    } else if (start == end) {
        wgt++;
        return wgt * segTree[idx];
    } else {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        return (querySegTree(segTree, left, start, mid, L, R, wgt) +
            querySegTree(segTree, right, mid + 1, end, L, R, wgt)) % m;
    }
}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    const int n = A.size();
    vector<int> segTree(n << 2);

    buildSegTree(segTree, 0, 0, n - 1, A);
    int x, y, z;
    int res;
    ll wgt;
    vector<int> ans;
    for (const auto& q : B) {
        x = q[0];
        y = q[1] - 1;
        z = q[2] - 1;

        if (x == 1) {
            z++;
            updateSegTree(segTree, 0, 0, n - 1, y, z);
        } else {
            wgt = 0;
            res = querySegTree(segTree, 0, 0, n - 1, y, z, wgt);
            ans.push_back(res);
        }
    }

    return ans;
}
