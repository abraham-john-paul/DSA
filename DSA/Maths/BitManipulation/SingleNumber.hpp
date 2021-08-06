#include "../../header.h"

int solve(const vector<int>& A) {
    int ans = 0;
    
    for (int e : A) {
        ans ^= e;
    }

    return ans;
}