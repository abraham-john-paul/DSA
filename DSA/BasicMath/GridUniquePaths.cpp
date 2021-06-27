#include <iostream>

using namespace std;

int findUniquePaths(int a, int A, int b, int B) {
    if ((a == (A - 1)) && (b == (B - 1))) {
        return 1;
    }

    if (a == A || b == B) {
        return 0;
    }

    return findUniquePaths(a + 1, A, b, B) + findUniquePaths(a, A, b + 1, B);
}

int uniquePaths(int A, int B) {
    return findUniquePaths(0, A, 0, B);
}

int main() {
    int A = 7;
    int B = 3;

    cout << uniquePaths(A, B);
    
    return 0;
}