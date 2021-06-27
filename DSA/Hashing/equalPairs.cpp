#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <limits.h>

using namespace std;

void print(vector<int> &A) {
    for(auto elem : A) {
        cout << elem << " ";
    }
    cout << endl;
}

bool lexicographical_compare(vector<int> &A, vector<int> &B) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > B[i]) {
            return false;
        } else if ((A[i] < B[i])) {
            return true;
        }
    }
    return true;
}

vector<int> equalPairs(vector<int> &A) {
    vector<int> res = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    if (!A.empty()) {
        using ll = long long;
        unordered_map<ll, pair<int, int>> um;
        vector<int> cur(4);
        int i, j;
        const int n = A.size();
        ll sum;
        auto itr = um.begin();
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                sum = A[i] + A[j];
                itr = um.find(sum);
                if (itr != um.end()) {
                    auto p = itr->second;
                        cur =  {p.first, p.second, i, j};
                    if (p.first < i && p.second < j && p.second < i) {
                        cout << ">>";
                        print(cur);
                        res = lexicographical_compare(res, cur) ? res : cur;
                        print(res);
                        
                    }
                } else {
                    um.insert({sum, {i, j}});
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> a = { 9, 5, 4, 9, 3, 6, 8, 7, 1, 2, 8, 7, 2, 9, 7, 1, 3, 9, 7, 8, 1, 0, 5, 5 };
    auto res = equalPairs(a);
    cout << "\n is res empty : " << res.empty() << endl;
    for(auto elem : res) {
        cout << elem << " ";
    }
    
    return 0;
}