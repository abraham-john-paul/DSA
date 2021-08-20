#include "../header.h"
int partition(vector<int>& A, int start, int end) {
    int pivot = A[end];
    int i = start - 1;

    for (int j = start; j <= (end - 1); j++) {
        if (A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[end]);
    return (i + 1);
}

void quicksort(vector<int>& A, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivotIdx = partition(A, start, end);
    quicksort(A, start, pivotIdx - 1);
    quicksort(A, pivotIdx + 1, end); 
}

