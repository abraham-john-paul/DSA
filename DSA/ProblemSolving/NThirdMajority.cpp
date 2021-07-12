#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int>& A) {
    int freq1 = 0;
    int cand1;
    int freq2 = 0;
    int cand2;

    const int target = A.size() / 3;
    for (const int e : A) {
         if (e == cand1) {
            freq1++;
        } else if (e == cand2) {
            freq2++;
        } else if (freq1 == 0) {
            cand1 = e;
            freq1 = 1;
        } else if (freq2 == 0) {
            cand2 = e;
            freq2 = 1;
        } else {
            freq1--;
            freq2--;
        }
    }
    freq1 = 0;
    freq2 = 0;
    for (const int e : A) {
        if (e == cand1) {
            freq1++;
        } else if (e == cand2) {
            freq2++;
        }
    }

    if (freq1 > target) {
        return cand1;
    } else if (freq2 > target) {
        return cand2;
    } else {
        return -1;
    }
}

int main() {
    vector<int> A = {1, 2, 3, 1, 1};
    cout << solve(A);
    return 0;
}