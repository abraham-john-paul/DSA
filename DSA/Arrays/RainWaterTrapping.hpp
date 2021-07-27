#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int> &A) {
    const int n = A.size();
    vector<int> suffixMaxHeights(A.begin(), A.end());
    
    for (int i = n - 2; i >= 0; i--) {
        suffixMaxHeights[i] = max(suffixMaxHeights[i], suffixMaxHeights[i + 1]);
    } 
    
    int prefixMaxHeight = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        prefixMaxHeight = max(prefixMaxHeight, A[i]);
        ans += (min(prefixMaxHeight, suffixMaxHeights[i]) - A[i]);
    }
    
    return ans;
}