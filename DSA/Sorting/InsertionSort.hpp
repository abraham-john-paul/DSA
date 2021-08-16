#include "../header.h"

void insertionSort(vector<int>& A) {
    const int nA = A.size();
    int i, j;
    int temp;
    for (i = 1; i < nA; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0) {
            if (temp < A[j]) {
                A[j + 1] = A[j];
            } else {
                break;
            }
            j--;
        }
        A[j + 1] = temp;
    }
}