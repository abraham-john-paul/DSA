#include "../header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        const int nHeight = height.size();
        int left = 0;
        int lMax = 0;
        int right = nHeight - 1;
        int rMax = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= lMax) {
                    lMax = height[left];
                } else {
                    ans += (lMax - height[left]);
                }
                left++;
            } else {
                if (height[right] >= rMax) {
                    rMax = height[right];
                } else {
                    ans += (rMax - height[right]);
                }
                right--;
            }
        }
        
        return ans;
    }
};