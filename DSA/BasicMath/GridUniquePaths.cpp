#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int uniquePaths(int A, int B) {
    vector<int> dp(B, 0);
    dp[0] = 1;
    for (int a = 0; a < A; a++) {
        for (int b = 0; b < B; b++) {
            if (b > 0) {
                dp[b] += dp[b - 1];
            }
        }
    }
    return dp[B - 1];
}

int main() {
    int A = 7;
    int B = 3; 

    cout << uniquePaths(A, B);
    
    return 0;
}