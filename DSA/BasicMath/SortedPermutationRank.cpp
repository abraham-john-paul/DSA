#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int factorial(int n) {
    int ans = 1;
    int i = 2;

    while (i <= n) {
        ans *= (i++);
    }

    return ans;
}

int findLesserCharCount(const string& A, char a, int start , int end) {
    int cnt = 0;
    while (start < end) {
        if (A[start++] < a) {
            cnt++;
        }
    }
    return cnt;
}

int findRank(string A) {
    using ull = unsigned long long;
    const int n = A.size();
    ull nFac = factorial(n);
    ull rank = 1;

    for (int i = 0; i < n; i++) {
        nFac /= (n - i);
        rank += (findLesserCharCount(A, A[i], i + 1, n) * nFac);
    }

    return rank;
}

int main() {
    string A = "acb";
    cout << findRank(A);
    return 0;
}