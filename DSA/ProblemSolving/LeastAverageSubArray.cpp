#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int leastAvgSubArray(vector<int> &A, int B) {
    const int n = A.size();
    int sum = accumulate(A.begin(), A.begin() + B, 0); // sum of first B elements
    cout << sum << endl;
    int leastSum = sum;
    int ans = 0;
    
    for (int i = 1; i <= n - B; i++) {
        sum -= A[i - 1];
        sum += A[i + B - 1];
        cout << sum << endl;
        if (leastSum > sum) {
            leastSum = sum;
            ans = i;
        }
    }

    return ans;
}

int main() {
    vector<int> A = {20, 3, 13, 5, 10, 14, 8, 5, 11, 9, 1, 11};
    int B = 9;
    cout << leastAvgSubArray(A, B);
    return 0;
}
