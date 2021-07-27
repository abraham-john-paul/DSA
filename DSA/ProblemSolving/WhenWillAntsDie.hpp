#include <bits/stdc++.h>

using namespace std;

int solve(int A, vector<int> &B, vector<int> &C) {
    int minLeft = *max_element(B.begin(), B.end());
    int minRight = *min_element(C.begin(), C.end());
    return max(minLeft, A - minRight);
}
