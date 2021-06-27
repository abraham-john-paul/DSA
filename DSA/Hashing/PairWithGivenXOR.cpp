#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findUniqueXORPairs(vector<int> &A, int B) {
    unordered_set<int> us(A.begin(), A.end());
    int res = 0;
    for  (const auto elem : us) {
        if(us.find(elem ^ B) != us.end()) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<int> v = {17, 18, 8, 13, 15, 7, 11, 5, 4, 9, 12, 6, 10, 14, 16, 3};
    int b = 5;
    auto res = findUniqueXORPairs(v, b);
    cout << res;
    return 0;
}