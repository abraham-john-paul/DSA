#include "../../header.h"

int solve(int A) {
    int xi = 0;
    int nBits = 0;

    while (A > 0) {
        nBits++;
        if ((A & 1) == 0) {
            xi = nBits;
        }
        A >>= 1;
    }
    int x = (xi == 0) ? 0 : (1 << (xi - 1));
    int y = 1 << nBits;
    
    return x ^ y;
}