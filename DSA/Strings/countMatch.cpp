#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solve(string A) {
    int count = 0;
    int j = 0;
    for (char c : A) {
        switch (c) {
            case 'b':
                if(j == 2) {
                    count++;
                }
                j = 1;
                break;
            case 'o':
                if (j == 1) {
                    j = 2;
                } else {
                    j = 0;
                }
                break;
            default:
                j = 0;
        }
    } 
    
    return count;
}

int main() {
    string s = "bboobobob";
    auto res = solve(s);
    cout << endl;
    cout << res;
    return 0;
}