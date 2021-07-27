#include <bits/stdc++.h>
using namespace std;
#include "commonOps.hpp"

int solve(vector<int> &A, int B) {
    int nElemsLessThanB = count_if(A.begin(), A.end(), [&B](int a) { return a <= B; });  
    int nSwaps = count_if(A.begin(), A.begin() + nElemsLessThanB, [&B](int a) { return a > B; });
    int ans = nSwaps;
    const int n = A.size();
    int j = nElemsLessThanB;
    for (int i = 1; i < n - nElemsLessThanB + 1; i++) {
        if (A[i - 1] > B) {
            nSwaps--;
        }
        if (A[j++] > B) {
            nSwaps++;
        }
        ans = min(ans, nSwaps);
    }
    
    return ans;
}