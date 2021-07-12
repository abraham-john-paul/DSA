#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

int solve(vector<int> &A) {
    for (auto& elem : A) {
        if (elem == 0) {
            elem = -1;
        }
    }

    unordered_map <int, int> um;
    auto itr = um.begin();

    int sum = 0;
    int ans = INT_MIN;
    const int n = A.size();
    
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == 0) {
            ans = max(ans, i + 1);
        } else {
            itr = um.find(sum);
            if(itr != um.end()) {
                ans = max(ans, i - itr->second);
            }
        }
        um.insert({sum, i});
    }
    return ans;
}


int main() {
    vector<int> A = {1, 0, 1, 0, 1};
    cout << solve(A);
    return 0;
}