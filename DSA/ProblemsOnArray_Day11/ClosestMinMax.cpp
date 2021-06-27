#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

int closestMinMax(vector<int> &A) {
    if(A.empty()) {
        return -1;
    }
    pair<int, int> minp = {A[0], 0};
    pair<int, int> maxp = {A[0], 0};

    int res = INT_MAX;
    const int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] >= maxp.first) {
                if (A[i] > maxp.first) {
                    maxp.first = A[i];
                    maxp.second = i;
                    res = abs(maxp.second - minp.second) + 1;
                } else {
                    maxp.first = A[i];
                    maxp.second = i;
                    res = min(res, abs(maxp.second - minp.second) + 1);
                }
                cout << res << "\n";
        }   
        if (A[i] <= minp.first) {
                if (A[i] < minp.first) {
                    minp.first = A[i];
                    minp.second = i;
                    res = abs(maxp.second - minp.second) + 1;
                } else {
                    minp.first = A[i];
                    minp.second = i;
                    res = min(res, abs(maxp.second - minp.second) + 1);
                }
                cout << res << "\n";
        } 
    }
    if (res == INT_MAX) {
        res = abs(maxp.second - minp.second) + 1;
    } 
    return res;
}

int main() {
    vector<int> v = {814, 761, 697, 483, 981 };
    cout << "max" << *max_element(v.begin(), v.end()) << endl;
    cout << "min" << *min_element(v.begin(), v.end()) << endl;
    auto res = closestMinMax(v);
    cout << res;
    return 0;
}