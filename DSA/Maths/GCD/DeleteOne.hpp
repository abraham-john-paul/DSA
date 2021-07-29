#include "../../header.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(vector<int> &A) {
    const int n = A.size();
    vector<int> suffixGCD(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        suffixGCD[i] = gcd(A[i], suffixGCD[i + 1]);
    }

    int prefixGCD = 0;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        ans = max(ans, gcd(prefixGCD, suffixGCD[i + 1]));
        prefixGCD = gcd(A[i], prefixGCD);
    }

    return ans;
}