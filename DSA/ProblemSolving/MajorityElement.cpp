#include <iostream>
#include <vector>

using namespace std;

int majorityElement(const vector<int> &A) {
    int majElem ;
    int majElemFreq = 0;
    const int n = A.size();
    for (int i = 0; i < n; i++) {
        if (majElemFreq == 0) {
            majElemFreq = 1;
            majElem = A[i];
        } else {
            if (A[i] != majElem) {
                majElemFreq--;
            } else {
                majElemFreq++;
            }
        }
    }

    return majElem;
}


int main() {
    vector<int> A = {2, 1, 2};
    cout << majorityElement(A);
    return 0;
}