#include "../header.h"

void buildSegTree(vector<int> &segTree, int idx, int start, int end, const vector<int> &A)
{
    if (start == end)
    {
        segTree[idx] = A[start];
    }
    else
    {
        int mid = start + ((end - start) >> 1);
        int left = (idx << 1) + 1;
        int right = left + 1;
        buildSegTree(segTree, left, start, mid, A);
        buildSegTree(segTree, right, mid + 1, end, A);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

void appendToSegTree(vector<int> &segTree, int idx, int start, int end, const int i, int const int val)
{
    if (i < start || i > end)
    {
        return;
    }
    if (start == end)
    {
        if (start == segTree.size())
        {
            segTree.push_back(val);
        }
        else
        {
            segTree[idx] = val;
        }
    }
    else
    {
        int mid = start + ((end - start) >> 1);
        int left = (idx << 1) + 1;
        int right = left + 1;
        appendToSegTree(segTree, left, start, mid, i, val);
        appendToSegTree(segTree, right, mid + 1, end, i, val);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

void updateSegTree(vector<int> &segTree, int idx, int start, int end, const int i, int const int val)
{
    if (i < start || i > end)
    {
        return;
    }
    if (start == end)
    {
        segTree[idx] = val;
    }
    else
    {
        int mid = start + ((end - start) >> 1);
        int left = (idx << 1) + 1;
        int right = left + 1;
        appendToSegTree(segTree, left, start, mid, i, val);
        appendToSegTree(segTree, right, mid + 1, end, i, val);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

void deleteFromSegTree(vector<int> &segTree, int idx, int start, int end, const int i)
{
    if (i < start || i > end)
    {
        return;
    }
    if (start == end)
    {
        segTree[idx] *= -1;
    }
    else
    {
        int mid = start + ((end - start) >> 1);
        int left = (idx << 1) + 1;
        int right = left + 1;
        appendToSegTree(segTree, left, start, mid, i);
        appendToSegTree(segTree, right, mid + 1, end, i);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

int querySegTree(vector<int> &segTree, int idx, int start, int end, const int L, const int R)
{
    if (start < L || end < R)
    {
        return 0;
    }
    if (L <= start && end <= R)
    {
        return segTree[idx];
    }
    int mid = start + ((end - start) >> 1);
    int left = (idx << 1) + 1;
    int right = left + 1;
    querySegTree(segTree, left, start, mid, L, R);
    querySegTree(segTree, right, mid + 1, end, L, R);
    return segTree[left] + segTree[right];
}

vector<int> solve(vector<int> &A, vector<vector<int>> &B)
{
    int n = A.size();
    vector<int> segTree(n << 2);
    buildSegTree(segTree, 0, 0, n - 1, A);
    int q, x, y;
    int i;

    vector<int> ans;
    int res;
    for (const auto &query : B)
    {
        q = query[0];
        x = query[1] - 1;
        y = query[2];

        switch (q)
        {
        case 1:
            // append x to segTree
            i = ((n - 1) >> 1);
            appendToSegTree(segTree, 0, 0, n - 1, i, x + 1);
            n++;
            break;
        case 2:
            // set A[x] = y
            updateSegTree(segTree, 0, 0, n - 1, x, y);
            break;
        case 3:
            // delete A[x]
            deleteFromSegTree(segTree, 0, 0, n - 1, x);
            break;
        case 4:
            // find sum [x, y]
            y--;
            res = querySegTree(segTree, 0, 0, n - 1, x, y);
            ans.push_back(res);
            break;
        }
    }

    return ans;
}
