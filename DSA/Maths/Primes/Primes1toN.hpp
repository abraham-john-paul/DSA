#include "../../header.h"

vector<int> findPrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> ans;
    ans.reserve(count(isPrime.begin() + 2, isPrime.end(), true));
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            ans.push_back(i);
        }
    }

    return ans;
}