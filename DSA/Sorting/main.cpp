// #include "MergeSort.hpp"
// #include "InsertionSort.hpp"
// #include "InversionCount.hpp"
// #include "AlternatePosNegNos.hpp"
// #include "QuickSort.hpp"
#include "RadixSort.hpp"

int main() {
    vector<int> A = {2, 4, 1, 5, 3};
    shuffle(A.begin(), A.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
    printArray(A);
    // mergeSort(A, 0, A.size() - 1);
    // insertionSort(A);
    // quicksort(A, 0, A.size() - 1);
    radixSort(A);
    printArray(A);

    // Inversion Count
    // vector<int> A = {3, 2, 1};
    // printValue(solve(A));
    // printArray(A);

    // Alternate Positive and Negetive Nos
    // vector<int> A = {-1, -2, -3, 4, 5};
    // printArray(solve(A));
    


    return 0;
}