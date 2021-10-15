#include "../header.h"

void buildSegmentTree(vector<int> &segTree, int idx, int start, int end)
{
    if (start == end)
    {
        segTree[idx] = 1;
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        buildSegmentTree(segTree, left, start, mid);
        buildSegmentTree(segTree, right, mid + 1, end);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

void updateSegmentTree(vector<int> &segTree, int idx, int start, int end, int i)
{
    if (i < start || end < i)
    {
        return;
    }
    if (start == end)
    {
        segTree[idx] = 0;
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        updateSegmentTree(segTree, left, start, mid, i);
        updateSegmentTree(segTree, right, mid + 1, end, i);
        segTree[idx] = segTree[left] + segTree[right];
    }
}

int querySegmentTree(const vector<int> &segTree, int idx, int start, int end, int k)
{
    if (k > segTree[idx])
    {
        return -1;
    }
    if (start == end)
    {
        return start;
    }
    int left = (idx << 1) + 1;
    int right = left + 1;
    int mid = start + (end - start) / 2;
    if (segTree[left] >= k)
    {
        return querySegmentTree(segTree, left, start, mid, k);
    }
    else
    {
        k -= segTree[left];
        return querySegmentTree(segTree, right, mid + 1, end, k);
    }
}

vector<int> Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> segTree(A << 2);
    buildSegmentTree(segTree, 0, 0, A - 1);
    int x, y;
    int res;
    vector<int> ans;

    for (const auto &query : B)
    {
        x = query[0];
        y = query[1];

        if (x == 0)
        {
            y--;
            updateSegmentTree(segTree, 0, 0, A - 1, y);
        }
        else
        {
            res = querySegmentTree(segTree, 0, 0, A - 1, y);
            ans.push_back(res == -1 ? res : res + 1);
        }
    }

    return ans;
}
