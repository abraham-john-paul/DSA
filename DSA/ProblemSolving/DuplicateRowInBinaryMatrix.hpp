#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solve(vector<vector<int> > &A) {
    const int r = A.size();
    if (r == 0) {
        return {};
    }
    const int c = A[0].size();
    vector<int> ans;
    ans.reserve(r - 1);

    unordered_set<long long> us;
    long long value;
    const int m = 1000000007;
    for (int i = 0; i < r; i++) {
        value = 0;
        for (int j = 0; j < c; j++) {
            value = (value % m + (A[i][j] << j) % m + m) % m;
        }
        if (us.find(value) == us.end()) {
            us.insert(value);
        } else {
            ans.push_back(i + 1);
        }
    }

    return ans;
}
