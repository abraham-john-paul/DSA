#include "../../header.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int cpFact(int A, int B) {
    int ans;
    
    for (int i = 1; i * i <= A; i++) {
        if (A % i == 0) {
            if (gcd(B, A / i) == 1) {
                return A / i;
            }
            if (gcd(B, i) == 1)
                ans = i;
        }
    }
    
    return ans;
}