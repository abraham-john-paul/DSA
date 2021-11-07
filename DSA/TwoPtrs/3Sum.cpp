#include "../header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto& A = nums;
        int i, j, k;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int sum, curSum;
        for (i = 0; i < n - 2; i++) {
            if (i == 0 || (nums[i - 1] != nums[i])) {
                j = i + 1;
                k = n - 1;
                sum = 0 - A[i];
                while (j < k) {
                    curSum = A[j] + A[k];
                    if (curSum == sum) {
                        ans.push_back({A[i], A[j], A[k]});
                        while (j < k && A[j] == A[j + 1]) j++;
                        while (j < k && A[k - 1] == A[k]) k--;
                        j++;
                        k--;
                    } else if (curSum > sum) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
        }
        
        return ans;
    }
};