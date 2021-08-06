#include "../../header.h"

int findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    
    const int n = A.size();
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, A[i] ^ A[i - 1]);
        if (ans == 0) {
            break;
        }
    }
    
    return ans;
}