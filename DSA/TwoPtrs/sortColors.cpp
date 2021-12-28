#include "../header.h"

void Solution::sortColors(vector<int> &A) {
    const int nA = A.size();
    if (nA <= 1) return;
    int i0 = 0;
    int i2 = nA - 1;
    int i = 0;
    while (A[i0] == 0) {
        i0++;
    }
    while (A[i2] == 2) {
        i2--;
    }
    i = i0;
    while (i <= i2) {
        switch (A[i]) {
            case 0:
                swap(A[i], A[i0]);
                while (A[i0] == 0) {
                    i0++;
                }
                if (i < i0)
                    i = i0;
                break;
            case 2:
                swap(A[i], A[i2]);
                while (A[i2] == 2) {
                    i2--;
                }
                break;
            default:
            i++;
        }
    }
}
