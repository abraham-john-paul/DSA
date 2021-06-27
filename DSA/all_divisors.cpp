#include <iostream>

using namespace std;

void printAllDivisors(int n) {
    int i = 1;
    for (; i * i < n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }
    for (; i * i >= 1; i--) {
        if(n % i == 0) {
            cout << n / i << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    printAllDivisors(n);
    return 0;
}