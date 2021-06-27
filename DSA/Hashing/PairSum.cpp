#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findPairs(const vector<int> &A, int B) {
    unordered_map<int, int> um;
    auto itr = um.begin();
    const int n = A.size();
    for  (int i = 0; i < n; i++) {
        itr = um.find(B - A[i]);
        if (itr == um.end()) {
            um.insert({A[i], i});
        } else {
            return {itr->second + 1, i + 1};
        }
    }
    return {};
}

int main() {
    vector<int> v = {2, 7, 11, 15};
    int b = 9;
    auto res = findPairs(v, b);
    if (!res.empty()) {
        cout << res.front() << " " << res.back();
    } else {
        cout << "Pair not found";
    }
    return 0;
}