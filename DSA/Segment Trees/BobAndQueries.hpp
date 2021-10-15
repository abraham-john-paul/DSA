#include "../header.h"

void updateTree(vector<int> &segmentTree, int idx, int start, int end, const int i, const int val)
{
    if (i < start || i > end)
    {
        return;
    }
    if (start == end)
    {
        segmentTree[idx] += val;
        if (segmentTree[idx] < 0)
        {
            segmentTree[idx] = 0;
        }
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        updateTree(segmentTree, left, start, mid, i, val);
        updateTree(segmentTree, right, mid + 1, end, i, val);
        segmentTree[idx] = segmentTree[left] + segmentTree[right];
    }
}

int queryTree(const vector<int> &segmentTree, int idx, int start, int end, const int L, const int R)
{
    if (end < L || R < start)
    {
        return 0;
    }
    else if (L <= start && end <= R)
    {
        return segmentTree[idx];
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        return queryTree(segmentTree, left, start, mid, L, R) +
               queryTree(segmentTree, right, mid + 1, end, L, R);
    }
}

vector<int> Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> segmentTree(A << 2);
    vector<int> ans;
    ans.reserve(B.size());
    int x, y, z;
    int res;
    for (const auto &query : B)
    {
        x = query[0];
        y = query[1] - 1;
        switch (x)
        {
        case 1:
        {
            updateTree(segmentTree, 0, 0, A - 1, y, 1);
            break;
        }
        case 2:
        {
            updateTree(segmentTree, 0, 0, A - 1, y, -1);
            break;
        }
        case 3:
        {
            z = query[2] - 1;
            res = queryTree(segmentTree, 0, 0, A - 1, y, z);
            ans.push_back(res);
            break;
        }
        }
    }

    return ans;
}
