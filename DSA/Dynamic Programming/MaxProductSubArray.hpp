#include "../header.h"

int Solution::maxProduct(const vector<int> &A)
{
    int maxSoFar = 1;
    int minSoFar = 1;
    int ans = INT_MIN;
    int temp;
    for (int e : A)
    {
        maxSoFar *= e;
        minSoFar *= e;
        if (e < 0) {
            temp = minSoFar;
            minSoFar = maxSoFar;
            maxSoFar = temp;
        } else if (e == 0) {
            maxSoFar = 1;
            minSoFar = 1;
        }
        if (e != 0)
            ans = max(ans, maxSoFar);
        else
            ans = max(ans, 0);
        if (maxSoFar < 0) {
            maxSoFar = 1;
        }
    }

    return ans;
}