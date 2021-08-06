#include "../../header.h"

int solve(int A, int B) {
    if (A == INT_MIN && B == -1) {
        return INT_MAX;
    }
    long long a = (A == INT_MIN) ? INT_MAX : abs(A);
    long long b = abs(B);
    int i = 0;
    long long ans = 0;
    printValues({a, b});
    while (a - b > 0) {
        do {
            if ((a - (b << (i + 1))) > 0) {
                i++;
            } else {
                break;
            }
            
        } while ((a - (b << i)) > 0);
        ans += 1 << i;
        a -= (b << i);
        printValues({ans, a});
        i = 0;
    }

    return ((A > 0 && B < 0) || (A < 0 && B > 0)) ? -ans : ans;
}