int Solution::solve(vector<int> &A) {
    const int nA = A.size();
    vector<int> suffixMax(nA);
    suffixMax.back() = A.back();
    for (int i = nA - 2; i >= 0; i--) {
        suffixMax[i] = max(A[i], suffixMax[i + 1]);
    }
    set<int> prefixSet;
    prefixSet.insert(A[0]);
    int maxSum = 0;
    for (int i = 1; i < nA - 1; i++) {
        prefixSet.insert(A[i]);
        
        auto itr = prefixSet.find(A[i]);
        
        if (itr == prefixSet.begin() || suffixMax[i] == A[i]) continue;
        itr--;
        maxSum = max(maxSum, *itr + A[i] + suffixMax[i]);
    }

    return maxSum;
}

