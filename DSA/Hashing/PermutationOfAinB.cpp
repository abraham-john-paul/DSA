#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool checkIfFreqsMatch(unordered_map<char, int>& um1, unordered_map<char, int> um2) {
    if (um1.size() > um2.size()) {
        return false;
    }
    auto p2 = um2.begin();
    for (const auto p1 : um1) {
        p2 = um2.find(p1.first);
        if (p2 == um2.end() || p1.second != p2->second) {
            return false;
        }
    }
    return true;
}

int findPermutationOfAinB(string A, string B) {
    unordered_map<char, int> charFreqInA;
    for (const char c : A) {
        if (charFreqInA.find(c) != charFreqInA.end()) {
            charFreqInA[c]++;
        } else {
            charFreqInA[c] = 1;
        }
    }
    const int nA = A.size();
    unordered_map<char, int> windowSizeCharFreqinB;
    int i = 0;
    for (; i < nA; i++) {
        if (windowSizeCharFreqinB.find(B[i]) != windowSizeCharFreqinB.end()) {
            windowSizeCharFreqinB[B[i]]++;
        } else {
            windowSizeCharFreqinB[B[i]] = 1;
        }
    }
    const int nB = B.size();
    int res = checkIfFreqsMatch(charFreqInA, windowSizeCharFreqinB) ? 1 : 0;
    
    while (i < nB) {
        windowSizeCharFreqinB[B[i - nA]]--;
        if(windowSizeCharFreqinB.find(B[i]) != windowSizeCharFreqinB.end()) {
            windowSizeCharFreqinB[B[i]]++;
        } else {
            windowSizeCharFreqinB[B[i]] = 1;
        }
        res += checkIfFreqsMatch(charFreqInA, windowSizeCharFreqinB) ? 1 : 0;
        i++;
    }

    return res;
}

int main() {
    string A = "p";
    string B = "pccdpeeooadeocdoacddapacaecb";
    cout << findPermutationOfAinB(A, B);
    // auto res = findPairs(v, b);
    // if (!res.empty()) {
    //     cout << res.front() << " " << res.back();
    // } else {
    //     cout << "Pair not found";
    // }
    return 0;
}