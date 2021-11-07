#include "../header.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo = 0;
        int n = nums.size();
        int hi = 0;
        int ans = 0;
        int flips = k;
        while (hi < n) {
            if (nums[hi] == 0) {
                if (flips > 0) {
                    flips--;
                } else {
                    while (flips == 0) {
                        if (nums[lo] == 0) {
                            flips++;
                        }
                        lo++;
                    }
                    hi--;
                }
            }
            ans = max(ans, hi - lo + 1);
            hi++;
        }
        return ans;
    }
};