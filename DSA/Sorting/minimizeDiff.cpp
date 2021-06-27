#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <unordered_map>
using namespace std;

void insertionSortAtEnd(vector<int> &A) {    
    const int n = A.size();
    int pos = n - 1; 
    while (pos >= 0) {
        if(A[pos - 1] > A[pos]) {
            swap(A[pos - 1], A[pos]);
            pos--;
        } else {
            break;
        }
    }
}

void insertionSortAtBegin(vector<int> &A) {    
    const int n = A.size();
    int pos = 0; 
    while (pos < n) {
        if(A[pos] > A[pos + 1]) {
            swap(A[pos], A[pos + 1]);
            pos++;
        } else {
            break;
        }
    }
}

int solve(vector<int> &A, int B) {
    const int n = A.size();
    int max = INT_MIN;
    int min = INT_MAX;
    unordered_map<int, int> um;
    for (const auto e : A) {
        if(um.find(e) == um.end()) {
            um[e] = 1;
        } else {
            um[e]++;
        }
        if (e > max) {
            max = e;
        }
        if(e < min) {
            min = e;
        }
    }

    int res = max - min;
    int fMax = um[max];
    int fMin = um[min];
    while (min < max) {
        if (B < std::min(fMax, fMin)) {
            break;
        }
        if (fMax < fMin) {
            B -= fMax;
            max--;
            if(um.find(max) != um.end()) {
                fMax += um[max];
            }
        } else {
            B -= fMin;
            min++;
            if(um.find(min) != um.end()) {
                fMin += um[min];
            }
        }
        res = max - min;
    }

    return res;
}

int main() {
    vector<int> v = {2, 6, 7, 5, 2};
    cout << solve(v, 6);

    return 0;
}