#include "../../header.h"

vector<int> solve(const vector<int>& A) {
    int Xr = 0;
    for (const int e : A) {
        Xr ^= e;
    }
    int i = 0;
    while ((i < 32) && !(Xr & (1 << i))) {
        i++;
    }

    int a = 0;
    int b = 0;

    for (const int e : A) {
        if (e & (1 << i)) {
            a ^= e;
        } else {
            b ^= e;
        }
    }

    return a < b ? vector<int>({a, b}) : vector<int>({b, a});
}