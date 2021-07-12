#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    const int n = A.size();
    vector<int> ans;
    ans.reserve(n - B + 1);
    
    deque<int> dq;
    int i = 0;

    for (; i < B; i++) {
        while (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for (i = B; i < n; i++) {
        ans.push_back(A[dq.front()]);

        while (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        while (!dq.empty() && dq.front() <= i - B) {
            dq.pop_front();
        }
    }
    ans.push_back(A[dq.front()]);
    
    return ans;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 2, 7, 1, 3, 6};
    int B = 6;
    auto ans = slidingMaximum(A, B);
    for (const auto& elem : ans) {
        cout << elem << " ";
    }
    return 0;
}