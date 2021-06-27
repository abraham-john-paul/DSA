#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solve(string A) {
    int change = 1;
    int start = 0;
    int end = A.size() - 1;

    while (start < end) {
        if (A[start++] != A[end--]) {
            if (change == 0) {
                return "NO";
            }
            change--;
        }
    }

    return A.size() & 1 || change == 0 ? "YES" : "NO";
}

int main() {
    string s = "aaaaaaaaaabaaaaaaaaa";
    auto res = solve(s);
    cout << endl;
    cout << res;
    return 0;
}