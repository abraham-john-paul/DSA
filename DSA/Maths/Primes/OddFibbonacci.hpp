#include "../../header.h"

pair<int, int> fibonacci(int N) {
    pair<int, int> p = {1, 1};

    for (int i = 2; i <= N; i++) {
        swap(p.first, p.second);
        p.second += p.first;
    }

    return p;
}

int solve(int A, int B) {
    // odd odd even
    int ans = 0;
    A--;
    B--;

    switch (A % 3) {
    case 1:
        A--;
        ans -= 1;
        break;
    case 2:
        A -= 2;
        ans -= 2;
        break;
    }
    switch (B % 3) {
    case 0:
        ans += 1;
        break;
    case 1:
        B -= 1;
        ans += 2;
        break;
    case 2:
        B -= 2;
        ans += 2;
        break;
    }
    ans += ((B - A) / 3) * 2;
    return ans;
}