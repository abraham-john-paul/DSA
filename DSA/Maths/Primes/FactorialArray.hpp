#include "../../header.h"

int solve(vector<int>& A) {
    using ull = unsigned long long;
    
    int N = *max_element(A.begin(), A.end());
    vector<int> isPrime(N + 1, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i] == 1) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    partial_sum(isPrime.begin(), isPrime.end(), isPrime.begin());
    
    unordered_map<int, ull> um;
    for (const int& e : A) {
        if (e != 1) {
            um[isPrime[e]]++;
        }
    }

    ull ans = 0;
    const int m = 1000000007;
    int value;
    for (const auto p : um) {
        value = (1 << p.second) % m;
        value--;
        ans = (ans + value) % m;

    }

    return ans;
}