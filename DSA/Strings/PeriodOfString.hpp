#include "header.h"

void doMatching(const string& A, vector<int>& Z, const int start, int& end) {
    const int nA = A.size();
    while ((end < nA) && (A[end] == A[end - start])) {
        end++;
    }
    Z[start] = end - start;
    end--;
}

void calculateZValues(const string& A, vector<int>& Z) {
    const int nA = A.size();
    int start = 0, end = 0;
    Z.front() = nA;
    int j;
    for (int i = 1; i < nA; i++) {
        if (i > end) { // outside the box
            start = i;
            end = i;
            doMatching(A, Z, start, end);
        } else { // inside the box
            j = i - start;
            if (Z[j] < (end - i + 1)) { 
                Z[i] = Z[j];
            } else {
                start = i;
                end++;
                doMatching(A, Z, start, end);
            }
        }
    }
}

int solve(string A) {
    const int nA = A.size();
    vector<int> Z(nA);
    calculateZValues(A, Z);
    
    int ans = nA;
    for (int i = 1; i < nA; i++) {
        if (Z[i] + i == nA) {
            return i;
        }
    }
    
    return ans;
}
