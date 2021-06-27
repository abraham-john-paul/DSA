#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int findMaxConsecutiveOnes(string A) {
    int nOnes = count(A.begin(), A.end(), '1');
    cout << nOnes << "\n";
    int res = 0;
    int nLeftOnes = 0;
    int nRightOnes = 0;
    int nZeros = 0;
    const int n = A.size();
    for (int i = 0; i < n; i++) {
        cout << nLeftOnes << " " << nRightOnes << " " << res << "\n" ;
        if (A[i] == '1') {
            switch (nZeros) {
            case 0:
                nLeftOnes++;
                break;
            case 1:
                nRightOnes++;
                break;
            }
        } else {
            if(nZeros == 1) {
                res = max(res, nLeftOnes + nRightOnes + 1);
                nLeftOnes = nRightOnes;
                nRightOnes = 0;
                nZeros = (nLeftOnes == 0) ? 0 : 1;
            } else {
                if (i != 0 && A[i - 1] == '1') {
                    nZeros = 1;
                }
            }
        }
    }

    res = max(res, nLeftOnes + nRightOnes + 1);

    if (nOnes - res < 0) { // we dont have a spare one to swap
        res -= 1;
    }

    return res;
}

int main() {
    string a = "010100110101";
    auto res =  findMaxConsecutiveOnes(a);
    cout << res << "\n";
    return 0;
}