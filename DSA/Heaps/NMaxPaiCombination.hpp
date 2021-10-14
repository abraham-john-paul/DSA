vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    const int n = A.size();
    vector<int> ans(n);
    
    using pip = pair<int, pair<int, int>>;
    priority_queue<pip> pq;
    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    unordered_set<string> visited;
    string key;
    int i, j;
    for (int k = 0; k < n; k++) {
        auto p = pq.top();
        pq.pop();
        ans[k] = p.first;
        i = p.second.first;
        j = p.second.second;

        if (i - 1 >= 0) {
            key = to_string(i - 1) + "_" + to_string(j);
            if (visited.find(key) == visited.end()) {
                visited.insert(key);
                pq.push({A[i - 1] + B[j], {i - 1, j}});
            }
        }
        if (j - 1 >= 0) {
            key = to_string(i) + "_" + to_string(j - 1);
            if (visited.find(key) == visited.end()) {
                visited.insert(key);
                pq.push({A[i] + B[j - 1], {i, j - 1}});
            }
        }
    }
    
    return ans;
}