#include "../header.h"

int minCut(string A) {
    const int nA = A.size();
    vector<vector<bool>> isPalindrome(nA, vector<bool>(nA, false));
    int i, j;
    for (i = 0; i < nA; i++) {
        isPalindrome[i][i] = true;
    }

    for (int l = 2; l <= nA; l++) {
        i = 0;
        j = i + l - 1;
        while (j < nA) {
            if (A[i] == A[j]) {
                isPalindrome[i][j] = (j == i + 1) || 
                    (isPalindrome[i + 1][j - 1]);
            }
            i++;
            j++;
        }
    }
    vector<int> cut(nA, nA);
    for (int i = 0; i < nA; i++) {
        if (isPalindrome[0][i]) {
            cut[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j + 1][i]) {
                    cut[i] = min(cut[i], 1 + cut[j]);
                }
            }
        }
    }

    return cut[nA - 1];
}