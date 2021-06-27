#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getLargest(string A) {
    auto pos_ = A.find("_");
    string t = A.substr(pos_ + 1);
    string s = A.erase(pos_);
    int n = s.size();
    sort(t.begin(), t.end(), greater<char>());
    int pos_t = 0;
    for (int i = 0; i < n; i++) {
        if (pos_t < t.size() && t[pos_t] > s[i]) {
            s[i] = t[pos_t];
            pos_t++;
        }
    }
    return s;
}


int main() {
    string s = "ittmcsvmoa_jktvvblefw";
    auto res = getLargest(s);
    cout << endl;
    cout << res;
    return 0;
}