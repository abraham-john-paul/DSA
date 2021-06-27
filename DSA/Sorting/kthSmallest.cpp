#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int kthsmallest(const vector<int> &A, int B) {
    priority_queue<int> pq;
    int i = 0;
    const int n  = A.size();
    // int k;
    for(; i < B; i++) {
        pq.push(A[i]);
        // cout << pq.top() << endl;
    }
    while(i < n) {
        if (A[i] < pq.top()) {
            pq.pop();
            pq.push(A[i]);
        }
        i++;
    }

    // while (pq.size() > 1) {
    //     pq.pop();
    // }
    return pq.top();
}

int main() {
    vector<int> v = {2, 1, 4, 3, 2};
    cout << kthsmallest(v, 3);
    return 0;
}