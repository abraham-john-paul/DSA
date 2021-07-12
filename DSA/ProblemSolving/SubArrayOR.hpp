#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
    long long ans = 0;
    const int m = 1000000007;
    const long long n = A.size();

    const long long maxSubArraysOR = (((n % m) * (n  + 1) % m) % m) >> 1;
    long long subArraysWithOnlyZeros;
    bool isAllZeros = false;
    long long nZeros;
    int p = 0;
    long long i = 0;
    long long curOR;
    int k = 32;
    while (k--) {
        curOR = maxSubArraysOR;
        nZeros = 0;
        isAllZeros = true;
        for (i = 0; i < n; i++) { 
            if (isAllZeros && A[i] >> p  != 0) {
                isAllZeros = false;
            }    
            if (((A[i] >> p) & 1) == 0) {
                nZeros = ((nZeros % m) - (i % m) + m) % m;
                while ((i < n) && (((A[i] >> p) & 1) == 0)) {
                    i = (i + 1) % m;
                }
                nZeros = (nZeros + i + m) % m;
                subArraysWithOnlyZeros = (((nZeros % m) * (nZeros + 1) % m) % m) >> 1;
                curOR = (curOR % m - subArraysWithOnlyZeros % m + m) % m;
                nZeros = 0;
                if (i == n) {
                    continue;
                }
            }
        }
        ans = (ans % m + ((1 << p) % m * curOR % m + m) % m + m) % m;
        p++;
        if (isAllZeros) {
            break;
        }
    }

    return ans;
}