#include "../header.h"

int log(int A, int B) {
    return log2(A) / log2(B);
}

vector<int> solve(int A) {
    vector<int> ans;
    int p = log(A, 3);;
    int n, k;
    ans.reserve(p + 1);

    while (A != 0) {
        p = log(A, 3);
        k = pow(3, p); 
        n = A / k;     
        for (int i = 0; i < n; i++) {
            ans.push_back(k);
        }
        A %= k;
    }

    return vector<int>(ans.rbegin(), ans.rend());
}