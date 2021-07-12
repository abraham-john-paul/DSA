#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int A) {
    vector<int> ans(A, 0);
    int start = 0;
    int end = 0;
    ans[end] = 1;
    A--;

    while(A--) {
        int mid = start + (end - start) / 2;
        if (((end - start + 1) & 1) == 0) {
            mid++;
        }
        
        for (int i = mid; i > 0; i--) {
            ans[i] += ans[i - 1];
        }

        end++;
        int n = end;
        while (start < n) {
            ans[n--] = ans[start++];
        }
        start = 0;
    }

    return ans;
}