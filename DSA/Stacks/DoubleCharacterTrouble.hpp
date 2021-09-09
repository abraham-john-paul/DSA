#include "../header.h"

string solve(string A) {
    const int nA = A.size();
    string ans;
    ans.reserve(nA);
    
    for (const char c : A) {
        if (!ans.empty() && ans.back() == c) {
            ans.pop_back();
        } else {
            ans.push_back(c);
        }
    }

    return ans;
}