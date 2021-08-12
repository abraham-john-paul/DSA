#include "../../header.h"

int solve(int A) {
    int ans = 0;
    int s = 0;
    for (int i = 1; i * (i + 1) / 2 <= A; i++) {
        s = 0;
        for (int j = max(1, A / i - i / 2); s < A; j++) {
            s =  (j - 1) * i + (i * (i + 1) / 2); 
            if (s == A) {
                ans++;
            }
        }
    }

    return ans;
}