#include "../header.h"

void merge(vector<int>& A, int start, int mid, int end) {
    vector<int> left(A.begin() + start, A.begin() + mid + 1);
    auto lItr = left.begin();
    auto lEnd = left.cend();
    
    vector<int> right(A.begin() + mid + 1, A.begin() + end + 1);
    auto rItr = right.begin();
    auto rEnd = right.cend();

    int a = start;
    auto aItr = A.begin() + start;

    while (lItr != lEnd && rItr != rEnd) {
        if (*lItr <= *rItr) {
            *aItr = *(lItr++);
        } else {
            *aItr = *(rItr++);
        }
        aItr++;
    }

    while (lItr != lEnd) {
        *(aItr++) = *(lItr++);
    }

    while (rItr != rEnd) {
        *(aItr++) = *(rItr++);
    }

    return;
}

void mergeSort(vector<int>& A, int start, int end) {
    if (start == end) {
        return;
    }

    const int mid = start + ((end - start) >> 1);
    mergeSort(A, start, mid);
    mergeSort(A, mid + 1, end);
    merge(A, start, mid, end);
}