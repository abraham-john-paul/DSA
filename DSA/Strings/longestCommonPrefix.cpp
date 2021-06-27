#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &A) {
    string res = A[0];
    int i = 1;
    const int n = A.size();
    int j;
    int m;
    while (i < n) {
        j = 0;
        m = min(res.size(), A[i].size());
        while (j < m) {
            if (res[j] != A[i][j]) {
                break;
            }
            j++;
        }
        if(j == 0) {
            return "";
        }
        if (j < res.size()) {
            res.erase(j);
        }
        i++;
    }
    return res;
}

int main() {
    vector<string> s = { "abcd", "abde", "abcf"};
    auto res = longestCommonPrefix(s);
    cout << res;
    return 0;
}