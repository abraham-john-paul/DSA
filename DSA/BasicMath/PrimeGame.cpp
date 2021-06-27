#include <iostream>

int GCD(int A, int B) {
    int temp;
    while (B) {
        temp = A % B;
        A = B;
        B = temp;
    }
    return A;
}

bool isCoprime(int A, int B) {
    if ((A & B) & 1) {
        return true;
    }
    return GCD(A, B) == 1;
}

int solve(int A, int B) {
    bool isOneWinner = false;

    while(true) {

        isOneWinner = !isOneWinner;
    }

    return isOneWinner ? 1 : 2;
}

int main() {
    int A = 10;
    int B = 5;
    std::cout << solve(A, B);
    return 0;
}