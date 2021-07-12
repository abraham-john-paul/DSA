#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <limits.h>
using namespace std;

void insertionSortAtBegin(vector<int> &A, int i) {    
    const int n = A.size();
    int pos = i; 
    while (pos < n) {
        if(A[pos] > A[pos + 1]) {
            swap(A[pos], A[pos + 1]);
            pos++;
        } else {
            break;
        }
    }
}

int solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int res = 0;
    int prev = A[0];
    const int n = A.size();
    int e;
    for (int i = 1; i < n; i++) {
        e = A[i];
        if (e <= prev) {
            prev += 1;
            res += (prev - e);
        } else {
            prev = e;
        }
    }
    return res;
}

int main() {
    vector<int> v = {51, 6, 10, 8, 22, 61, 56, 48, 88, 85, 21, 98, 81, 76, 71, 68, 18, 6, 14, 23, 72, 18, 56, 30, 97, 100, 81, 5, 99, 2, 85, 67, 46, 32, 66, 51, 76, 53, 36, 31, 81, 56, 26, 75, 69, 54, 54, 54, 83, 41, 86, 48, 7, 32, 85, 23, 47, 23, 18, 45, 79, 95, 73, 15, 55, 16, 66, 73, 13, 85, 14, 80, 39, 92, 66, 20, 22, 25, 34, 14, 51, 14, 17, 10, 100, 35, 9, 83, 31, 60, 24, 37, 69, 62};
    cout << solve(v);

    return 0;
}