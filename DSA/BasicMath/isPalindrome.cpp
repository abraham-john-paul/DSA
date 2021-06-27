#include <iostream>

using namespace std;

int isPalindrome(int A) {
    unsigned long long m = 1;
    while (A >= m * 10) {
        m *= 10;
    }
    cout << m << "\n";
    while (A != 0) {
        cout << A / m << " " << A%10 << "\n";
        if ((A % 10) != (A / m)) {
            return false;
        }
        A %= m;
        A /= 10;
        m /= 100;
        cout << A << " " << m << " << \n";
    }
    
    return true;
}

int main() {
    cout << isPalindrome(2147447412);
    return 0;
}