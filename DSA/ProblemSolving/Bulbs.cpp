#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& A) {
    const int n = A.size();
    int nToggles = 0;
    for (const int bulb : A) {
        if (nToggles & 1) {
            if (bulb == 1) {
                nToggles++;
            }
        } else {
            if (bulb == 0) {
                nToggles++;
            }
        }
    }
    return nToggles;
}

int main() {
    vector<int> A = {1,0,1,0};
    cout << solve(A);
    return 0;
}