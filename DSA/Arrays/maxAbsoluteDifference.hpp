#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    const int n = A.size();

    int xMax = INT_MIN;
    int xMin = INT_MAX;
    int yMax = INT_MIN;
    int yMin = INT_MAX;

    for (int i = 0; i < n; i++) {
        xMax = max(xMax, A[i] - i);
        xMin = min(xMin, A[i] - i);
        yMax = max(yMax, A[i] + i);
        yMin = min(yMin, A[i] + i);
    }

    return max(xMax - xMin, yMax - yMin);
}
