#include "../../header.h"

int solve(int A) {
    vector<int> ans(A + 1);
    int m = 1000000007;
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

        for (j = mid; j > 0; j--) {
                ans[j] = (ans[j] + ans[j - 1]) % m;
        }
        r = mid + 1;
        while (l >= 0) {
            ans[r++] = ans[l--];
        }
        end++;
    }

    long long powerOf2 = 1;

    long long sum = 0;
    long long res;
    for (i = 2; i <= A; i++) {
        res = (ans[i] * i) % m;
        res = (res * (i - 1)) % m;
        res = (res * powerOf2) % m;

        sum = (sum + res) % m;
        powerOf2 = (powerOf2 * 2) % m;
    }

    return sum;
}