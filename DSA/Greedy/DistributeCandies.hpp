int Solution::candy(vector<int> &A) {
    int nA = A.size();
    vector<int> dist(nA, 1);
    int i;
    for (i = 1; i < nA; i++) {
        if (A[i] > A[i - 1]) {
            dist[i] = dist[i - 1] + 1;
        }
    }
    
    for (i = nA - 2; i >= 0; i--) {
        if (A[i] > A[i + 1]) {
            dist[i] = max(dist[i], dist[i + 1] + 1);
        }
    }
    
    int ans = 0;
    for (int c : dist) {
        ans += c;
    }
    
    return ans;
}