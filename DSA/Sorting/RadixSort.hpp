#include "../header.h"

void radixSort(vector<int>& A) {
    vector<int> buckets[10];
    int maxElement = *max_element(A.begin(), A.end());
    int digit;
    int j;
    for (int i = 1; i <= maxElement; i *= 10) {
        for (const int& e : A) {
            digit = (e / i) % 10;
            buckets[digit].push_back(e);
        }
        j = 0;
        for (auto& bucket : buckets) {
            for (const int& e : bucket) {
                A[j++] = e;
            }
            bucket.clear();
        }
    }
}