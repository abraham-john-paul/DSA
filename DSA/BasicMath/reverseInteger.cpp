#include <iostream>
#include <string>
using namespace std;

int reverseInteger(int A) {
    bool isNegetive = A < 0;
    if (isNegetive) {
        A *= -1;
    }
    int ans = 0;
    while (A > 0) {
        ans += (A % 10);
        A /= 10;
        if (A > 0) {
            ans *= 10;
        } 
    }
    if (isNegetive) {
        ans *= -1;
    }
    return ans;
}

int main() {
    cout << reverseInteger(-123);
    return 0;
}