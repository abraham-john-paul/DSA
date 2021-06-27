#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string a) {
    int start = 0;
    int end = a.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= mid) {
        if (a[start++] != a[end--]) {
            return false;
        }
    }
    
    return true;
}

void incrementString(string& a) {
    bool carry = true;
    int n = 0;

    for (auto itr = a.rbegin(); itr != a.rend(); itr++) {
        n = *itr - '0';
        if (carry) {
            if(n == 9) {
                n = 0;
            } else {
                n++;
                carry = false;
            }
        } else {
            break;
        }
        *itr = n + '0';
    }
    if (carry) {
        a.insert(0, "1");
    }
}

string findNextSmallestPalindrome(string A) {
    incrementString(A);
    while (!isPalindrome(A)) {
        incrementString(A);
    }

    return A;
}


int main() {
    string a = "999";
    auto res = findNextSmallestPalindrome(a);
    cout << res << "\n";
    return 0;
}
