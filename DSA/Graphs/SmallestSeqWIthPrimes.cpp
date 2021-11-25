#include "../header.h"

vector<int> solve(int A, int B, int C, int D) {
    set<int> s;
    vector<int> ans(D);
    auto primes = {A, B, C};
    for (auto p : primes) {
        s.insert(p);
    }
    int i = 0;
    while (i  < D) {
        ans[i] = *s.begin();
        s.erase(s.begin());
        for (int p : primes) {
            int val = ans[i] * p;
            if (s.find(val) == s.end())
                s.insert(val);
        }
        i++;
    }

    return ans;
}