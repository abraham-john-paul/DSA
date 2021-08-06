#include "../../header.h"

int countPrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            if (i * 2 <= N) {
                cnt++;
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            } else {
                break;
            }
        }
    }
    
    return cnt;
}
int solve(int A) {
    int n = countPrimes(A);
    return n * (n - 1) / 2;
}
