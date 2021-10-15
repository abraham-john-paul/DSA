void buildSegmentTree(vector<int> &segmentTree, const vector<int> &A,
                      int idx, int start, int end)
{
    if (start == end)
    {
        segmentTree[idx] = A[start];
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        buildSegmentTree(segmentTree, A, left, start, mid);
        buildSegmentTree(segmentTree, A, right, mid + 1, end);
        segmentTree[idx] = min(segmentTree[left], segmentTree[right]);
    }
}

void updateSegmentTree(vector<int> &segmentTree,
                       int idx, int start, int end,
                       const int val, const int i)
{
    if (i < start || i > end)
    {
        return;
    }

    if (start == end)
    {
        segmentTree[idx] = val;
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left = (idx << 1) + 1;
        int right = left + 1;
        updateSegmentTree(segmentTree, left, start, mid, val, i);
        updateSegmentTree(segmentTree, right, mid + 1, end, val, i);
        segmentTree[idx] = min(segmentTree[left], segmentTree[right]);
    }
}

int querySegmentTree(const vector<int> &segmentTree,
                     int idx, int start, int end,
                     const int L, const int R)
{
    if (R < start || end < L)
    {
        return INT_MAX;
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
        return min(querySegmentTree(segmentTree, left, start, mid, L, R),
                   querySegmentTree(segmentTree, right, mid + 1, end, L, R));
    }
}

vector<int> solve(vector<int> &A, vector<vector<int>> &B)
{
    const int n = A.size();
    vector<int> segmentTree(n << 2);
    buildSegmentTree(segmentTree, A, 0, 0, n - 1);

    int x, y, z;
    int res;
    vector<int> ans;
    for (const auto &query : B)
    {
        x = query[0];
        y = query[1] - 1;
        z = query[2] - 1;
        switch (x)
        {
        case 0:
            z++;
            updateSegmentTree(segmentTree, 0, 0, n - 1, z, y);
            break;
        case 1:
            res = querySegmentTree(segmentTree, 0, 0, n - 1, y, z);
            ans.push_back(res);
            break;
        }
    }

    return ans;
}