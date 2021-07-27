#include <bits/stdc++.h>
using namespace std;

void pathOperation(deque<string>& s, const string& dirName) {
    if (dirName == "..") {
        if (!s.empty()) {
            s.pop_back();
        }
    } else if (dirName != ".") {
        s.push_back(dirName);
    }
}

string simplifyPath(string A) {
    const int n  = A.size();
    if (n <= 1) {
        return "/";
    }

    deque<string> s;
    int slashPos = 0;
    string dirName;
    int i = 1;
    for (; i <= n; i++) {
        if (A[i] == '/') {
            dirName  = A.substr(slashPos + 1, i - slashPos - 1);
            if (!dirName.empty()) {
                pathOperation(s, dirName);
            }
            slashPos = i;
        }
    }

    dirName  = A.substr(slashPos + 1, i - slashPos);
    if (!dirName.empty()) {
        pathOperation(s, dirName);
    }
    
    string ans = s.empty() ? "/" : "";
    for (const auto& dir : s) {
        ans += "/" + dir;
    }
    return ans;
}