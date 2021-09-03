#include "../header.h"

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    const int nA = A.size();
    long long ans;
    long long sum;
    long long min = LLONG_MAX;
    int start, end;
    for (int i = 0; i < nA - 2; i++) {
        start = i + 1;
        end   = nA - 1;
        
        while (start < end) {
            sum = (long long)A[start] + A[end] + A[i];
            if (min > abs(B - sum)) {
                min = abs(B - sum);
                ans = sum;
            }
            if (sum < B) {
                start++;
            } else {
                end--;
            }
        }
    }
    return ans;
}
