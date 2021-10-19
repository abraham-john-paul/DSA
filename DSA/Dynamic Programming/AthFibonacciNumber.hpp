#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n, vector<int>& dp) {
    if (n < 2) {
        return n;
    }
    if (dp[n] == -1) {
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    }
    return dp[n];
}

int main()  {
    int n;
    
    cin >> n;
    // Bottom Up Approach
    // if (n < 2) {
    //     cout << n << "\n"; 
    // } else {
    //     int a = 1, b = 1;
    //     int sum;
    //     for (int i = 3; i <= n; i++) {
    //         sum = a + b;
    //         a = b;
    //         b = sum;
    //     }
        
    //     cout << b << "\n";
    // }
    
    // Top Down Approach
    // vector<int> dp(n + 1, -1);
    // cout << fibonacci(n, dp);
    return 0;
}