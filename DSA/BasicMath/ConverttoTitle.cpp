#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int A) {
    string ans = "";
    int m;

    while (A != 0) {
        m = (A - 1) % 26;
        ans = static_cast<char>('A' + m) + ans;
        A  = A / 26;
    }

    return ans;
}

int main() {
    cout << convertToTitle(943566);
    return 0;
}