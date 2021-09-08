#include "../header.h"

int doMatching(vector<int>& Z, const string& A, int start, int end) {
    const int nA = A.size();
    
    while (end < nA && A[end - start] == A[end]) {
        end++;
    }
    
    Z[start] = end - start;
    return end - 1;
}

void calculateZValues(vector<int>& Z, const string& A) {
    const int nA = A.size();
    int start = 0;
    int end = 0;
    
    for (int i = 1; i < nA; i++) {
        if (end < i) {
            start = i;
            end = doMatching(Z, A, start, i);
        } else {
            if (Z[i - start] < (end - i + 1)) {
                Z[i] = Z[i - start];
            } else {
                start = i;
                end = doMatching(Z, A, start, end + 1);
            }
        }
    }
}

int solve(string A) {
    const int nA = A.size();
    string revA = A;
    reverse(revA.begin(), revA.end());
    const char delimiter = '$';
    revA = A + delimiter + revA;
    const int n = revA.size();
    
    vector<int> Z(n);
    calculateZValues(Z, revA);
    
    int i = n - 1;
    int ans = INT_MAX;
    while (revA[i] != delimiter) {
        if (Z[i] + i == n) {
            ans = min(ans, nA - Z[i]);
        }
        i--;
    }
    
    return ans;
}