#include <iostream>
#include <string>

using namespace std;

int findAGCount(string A) {
    int res = 0;
    int aCount = 0;
    const int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] == 'A') {
            aCount++;
        } else if (A[i] == 'G') {
            res += aCount;
        }
    }
    return res; 
}


int main() {
    string a = "AAG";
    auto res = findAGCount(a);
    cout << res << "\n";
    return 0;
}
