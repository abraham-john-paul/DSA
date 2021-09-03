#include "../header.h"

int isValid(const unordered_map<char, int>& fMapA, const unordered_map<char, int>& fMapB) {
    int len = 0;

    for (const auto& pB : fMapB) {
        auto itrA = fMapA.find(pB.first);
        if (itrA != fMapA.end()) {
            if (itrA->second >= pB.second) {
                len += itrA->second;
            } else {
                return INT_MAX;
            }
        } else {
            return INT_MAX;
        }
    }

    return len;
}

string minWindow(string A, string B) {
    const int nB = B.size();
    unordered_map<char, int> fMapA, fMapB;
    for (const char& c : B) {
        fMapB[c]++;
    }
    
    int count = 0;
    int start = 0;
    int end = 0;
    const int nA = A.size();
    vector<int> ans(2);
    int minLen = nA;

    while (end < nB) {
        fMapA[A[end]]++;
        end++;
    }
    while (end < nA) {
        while(isValid(fMapA, fMapB) == INT_MAX) {
            fMapA[A[end]]++;
            end++;
        }
        if (minLen > (end - start)) {
            ans = {start, end - 1};
        }
        while (isValid(fMapA, fMapB) != INT_MAX) {
            fMapA[A[start]]--;
            start++;
        }
    }

    return A.substr(ans.front(), ans.back() - ans.front() + 1);
}
