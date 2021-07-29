#include <bits/stdc++.h>
using namespace std;

int solve(int A) {
    int ans = 0;
    int multiplier = 5;
    
    while (A != 0) {
        if (A & 1) {
            ans += multiplier;
        }
        multiplier *= 5;
        A >>= 1;
    }

    return ans;
}