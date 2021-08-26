#include "../header.h"

long long fastPower(long long a, int p) {
    long long ans = 1;
    
    while (p > 0) {
        if (p & 1) {
            ans *= a;
        }
        a *= a;
        p >>= 1;
    }
    
    return ans;
}

long long validate(long long N, int lenOf1s) {
    long long start = 2;
    long long end = N - 1;
    long long mid, sum;
    while (start <= end) {
        mid = start + (end - start) / 2;
        sum = 1;
        for (int i = 1; i < lenOf1s; i++) {
            sum += fastPower(mid, i);
        }
        if (sum == (N)) {
            return mid;
        } else if (sum > (N)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return LLONG_MAX;
}

string solve(string A) {
    long long N = stoll(A);
    long long ans = N - 1;
    for (int i = 63; i >= 1; i--) {
        ans = min(ans, validate(N, i));
    }
    
    return to_string(ans);
}