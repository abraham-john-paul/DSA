#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> solve(int A, int B, int C, int D) {
    vector<int> ans;
    ans.reserve(D);

    vector<int> P = {A, B, C};
    
    ans.push_back(1);

    unordered_map<int, int> um;
    for (const int e : P) {
        um.insert({e, 0});
    }
    int curMin = INT_MAX;
    int i;
    const int nP = P.size();
    while (D > 0) {
        curMin = INT_MAX;
        for (i = 0; i < nP; i++) {
            curMin = min(curMin, ans[um[P[i]]] * P[i]);
        }
        ans.push_back(curMin);
        for (i = 0; i < nP; i++) {
            if (curMin == ans[um[P[i]]] * P[i]) {
                um[P[i]]++;
            }
        }
        D--;
    }
    copy(ans.begin() + 1, ans.end(), ans.begin());
    ans.pop_back();
    return ans;
}

int main() {
    int A = 3;
    int B = 11;
    int C = 7;
    int D = 50;
    auto ans = solve(A, B, C, D);
    for (int elem : ans) {
        cout << elem << " ";
    }
    return 0;
}