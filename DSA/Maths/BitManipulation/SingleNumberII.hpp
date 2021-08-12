#include "../../header.h"

int solve(const vector<int>& A) {
    const int n = A.size();
    int ans = 0;
    int count = 0;
    for (int i = 0; i < 32; i++) {
        for (const int e : A) {
            if ((e & (1 << i))) {
                count++;
            }
        }

        if (count % 3 != 0) {
            ans |= (1 << i);
        }
        count = 0;
    }

    return ans;
}