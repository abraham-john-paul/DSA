#include "../header.h"

#define m int(1e9 + 7)
#define ll long long
#define pii pair<int, int>

int solve(vector<int> &A, vector<int> &B) {    
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    vector<pii> cars;
    for (int i = 0; i < n; i++) {
        cars.emplace_back(A[i], B[i]);
    }
    ll ans = 0;
    sort(cars.begin(), cars.end());
    int day = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].first > day) {
            pq.push(cars[i].second);
            day++;
        } else {
            if (cars[i].second > pq.top()) {
                pq.pop();
                pq.push(cars[i].second);
            }
        }
    }
    
    while (!pq.empty()) {
        ans = (ans + pq.top()) % m;
        pq.pop();
    }

    return ans;
}
