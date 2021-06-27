#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int findRank(string A) {
    int ans = 1;
    
    string curPerm = A;
    sort(curPerm.begin(), curPerm.end()); // Rank 1
    
    while (curPerm != A) {
        next_permutation(curPerm.begin(), curPerm.end());
        ans++;
    }

    return ans;
}

int main() {
    string A = "acb";
    cout << findRank(A);
    return 0;
}