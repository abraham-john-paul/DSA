int solve(vector<int> &A) {
    sort(A.begin(), A.end());
    if(A.size() >= 1) {
        int d = A[1] - A[0];
        const int n = A.size();
        for (int i = 1; i < n - 1; i++) {
            if(A[i + 1] - A[i] != d) {
                return false;
            }
        }
    }

    return true;
}
