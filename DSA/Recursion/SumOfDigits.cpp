#include <iostream>

using namespace std;

int sumOfDigits(int A, int ans) {
    if (A == 0) {
        return ans;
    }
    return sumOfDigits((A / 10), ans + (A % 10)); // Using tail recursion optimization
}

int main() {
    auto ans = sumOfDigits(123, 0);

    cout << ans;
    return 0;
}