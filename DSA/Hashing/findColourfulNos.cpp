#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

long long pdtOfDigits(string a) {
    long long res = 1;
    for (const char c : a) {
        res *= (c - '0');
    }
    return res;
}

int findColorfulNos(int A) {
    string N = to_string(A);
    long long k;
    string ks;
    unordered_set<long long> us;
    const int n = N.size();
    for(int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ks = N.substr(i, j - i + 1 );
            cout << ks << " ";
            k = pdtOfDigits(ks);
            if(us.find(k) != us.end()) {
                return 0;
            }
            us.insert(k);
        }
    }
    return 1;
}

int main() {
    int a = 236;
    int res = findColorfulNos(a);
    cout << res;
    
    return 0;
}
