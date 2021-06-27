#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

bool lexicographicOrder(const string& A, const string& B, unordered_map<char, int>& um) {
    const int n = A.size() < B.size() ? A.size() : B.size();

    for (int i = 0; i < n; i++) {
        if(um[A[i]] < um[B[i]]) {
            return true;
        } else if (um[A[i]] > um[B[i]]) {
            return false;
        }
    }
    return A.size() <= B.size();
}

int isLexicographicallySorted(vector<string> &A, string B) {
    unordered_map<char, int> um;
    for (int i = 0; i < B.size(); i++) {
        um.insert({B[i], i});
    }

    for (int i = 0; i < A.size() - 1; i++)  {
        if(!lexicographicOrder(A[i], A[i + 1], um)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<string> A = {"fine", "none", "no"};
    string B = "qwertyuiopasdfghjklzxcvbnm";
    cout << isLexicographicallySorted(A, B);
    
    return 0;
}
