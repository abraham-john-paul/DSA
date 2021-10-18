#include "../header.h"

struct Node {
    int sum = 0;
    int prefixSum = 0;
    int suffixSum = 0;
    int ans = 0;
};

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    const int n = A.size()
    vector<int> suffixSum(A.begin(), A.end());
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] += suffixSum[i - 1];
    }
}
