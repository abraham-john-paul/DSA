#include "../header.h"



int trailingZeroes(int A) {
    long long powerof5 = 5;
    long long ans = 0;
    while (A / powerof5 >0) {
        ans += A / powerof5;
        powerof5 *= 5;
    }

    return ans;
}