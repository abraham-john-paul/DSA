#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int findEquilibriumIndex(vector<int> &A) {
    int leftSum = 0;
    int rightSum = accumulate(A.begin(), A.end(), 0);
    const int n = A.size();
    for (int i = 0; i < n; i++) {
        rightSum -= A[i];
        if(leftSum == rightSum) {
            return i;
        }
        leftSum += A[i];
    }
    return -1;
}

int main() {
    vector<int> A = {-7, 1, 5, 2, -4, 3, 0};
    cout << findEquilibriumIndex(A);
    return 0;
}