#include "../../header.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(vector<int> &A) {
    int ans = 0;
    for (const int health : A) {
        ans = gcd(ans, health);
    }

    return ans;
}