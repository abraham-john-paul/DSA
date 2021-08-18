#include "../header.h"

string largestNumber(const vector<int> &A) {
    const int nA = A.size();
    vector<string> V;
    V.reserve(nA);
    
    for_each(A.begin(), A.end(), [&V](int a) mutable {
        V.push_back(to_string(a));
    });
    
    sort(V.begin(), V.end(), [](auto& s1, auto& s2) {
        return s1 + s2 > s2 + s1;
    });
    
    string ans;
    ans.reserve(nA);
    if (V.front() == "0") {
        return "0";
    }
    for(const auto& s : V) {
        ans += s;
    }
    
    return ans;
}
