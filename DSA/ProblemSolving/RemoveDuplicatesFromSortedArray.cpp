#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &A) {
    const int n = A.size();
    
    vector<int> ans;
    ans.reserve(n);
    
    ans.push_back(A[0]);
    
    for (int i = 1; i < n; i++) {
        if (A[i] != ans.back()) {
            ans.push_back(A[i]);
        }
    }

    return ans;
}


int main() {
    vector<int> A = {1 2 2 3 3};
    auto ans = solve(A);
    for (const int e : ans) {
        cout << e << " ";
    }
    return 0;
}