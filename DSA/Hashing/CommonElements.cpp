#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> findCommonElements(vector<int> &A, vector<int> &B) {
    vector<int> res;
    unordered_map<int, int> um;
    res.reserve(um.size());
    for (const auto elem : A) {
        if (um.find(elem) != um.end()) {
            um[elem]++;
        } else {
            um[elem] = 1;
        }
    }
    auto itr = um.begin();
    for (const auto elem : B) {
        itr = um.find(elem);
        if(itr != um.end() && itr->second > 0) {
            res.push_back(elem);
            itr->second--;
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {2, 3, 1, 2};
    auto res = findCommonElements(a, b);

    for(auto elem : res) {
        cout << elem << " ";
    }
    
    return 0;
}