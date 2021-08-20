#include "../header.h"

void radixSort(vector<int>& A) {
    int maxElem = *max_element(A.begin(), A.end());
    vector<int> buckets[10];
    int digit;
    int i, j, k;
    for (i = 1; i <= maxElem; i *= 10) {
        for (const int e : A) {
            digit = (e / i) % 10;
            buckets[digit].push_back(e);
        }
        k = 0;
        for (j = 0; j < 10; j++) {
            for (const int e : buckets[j]) {
                A[k++] = e;
            }
            buckets[j].clear();
        }
    }
}