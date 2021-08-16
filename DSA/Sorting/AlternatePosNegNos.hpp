#include "../header.h"

void reverse(vector<int>& A, int start, int end) {
    while(start < end) {
        swap(A[start++], A[end--]);
    }
}

void rotateRight(vector<int>& A, int start, int end) {
    reverse(A, start, end - 1);
    reverse(A, start, end);
}

void operation(vector<int>& A, int start, bool isNegetive) {
    int end = find_if(A.begin() + start + 1, A.end(), [isNegetive](int a) {
        return isNegetive ? a < 0 : a >= 0;
    }) - A.begin();
    if (end != A.size()) {
        rotateRight(A, start, end);
    }
}
 
vector<int> solve(vector<int> &A) {
    int start = 0;
    int end  = 0;
    bool isNegetive = true;
    const int nA = A.size();
    for (int i = 0; i < nA; i++) {
        if (isNegetive) {
            if (A[i] >= 0) {
                operation(A, i, isNegetive);
            }
        } else {
            if (A[i] < 0) {
                operation(A, i, isNegetive);
            }
        }
        isNegetive = !isNegetive;
    }

    return A;
}