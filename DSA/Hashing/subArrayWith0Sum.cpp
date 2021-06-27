#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool subArrayWith0Sum(vector<int> &A) {
    unordered_set<long long> us;
    long long cumSum = 0;
    us.insert(0);
    auto itr = us.begin();
    for (const int elem : A) {
        cumSum += elem;
        itr = us.find(cumSum);

        if (itr != us.end()) {
            return true;
        }

        us.insert(cumSum);
    }

    return false;
}

int main() {
    vector<int> v = {-1, 1, 2, 3, 4, 5};
    auto res = subArrayWith0Sum(v);
    cout << "Given array contains 0 sum subarray : " << (res ? "true" : "false") << "\n";
    return 0;
}