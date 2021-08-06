#include "../../header.h"

int solve(int A, int B, int C) {
    vector<int> ans(B + 1);
    ans.front() = 1;
    int end = 0;
    int mid;
    int n;
    int i, j; 
    int l, r;
    for (i = 0; i < A; i++) {
        mid = end / 2;
        n = end + 1;
        l = mid;
        if ((n & 1) == 0) {
            mid++;
        }

        if (mid > B) {
            j = B;
        } else {
            j = mid;
        }

        for (; j > 0; j--) {
                ans[j] = (ans[j] + ans[j - 1]) % C;
        }
        r = mid + 1;
        while (l >= 0) {
            if (r <= B) {
                ans[r++] = ans[l--];
            } else {
                break;
            }
        }
        end++;
    }

    return ans[B];
}