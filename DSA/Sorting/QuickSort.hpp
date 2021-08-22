#include "../header.h"

int partition(vector<int>& A, int start, int end) {
    int r = rand() % (end - start + 1) + start;
    swap(A[r], A[end]);
    
    int pIdx = start;
    int j = start;
    
    while (j < end) {
        if (A[j] < A[end]) {
            swap(A[j], A[pIdx]);
            pIdx++;
        }
        j++;
    }
    
    swap(A[pIdx], A[end]);
    return pIdx;
}

void quicksort(vector<int>& A, int start, int end) {
    if (start >= end) {
        return;
    }    
    int pivotIndex = partition(A, start, end);
    quicksort(A, start, pivotIndex - 1);
    quicksort(A, pivotIndex + 1, end);
}
