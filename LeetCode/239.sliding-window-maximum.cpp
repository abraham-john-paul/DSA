/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        const int nNums = nums.size();
        vector<int> ans(nNums - k + 1);
        int j = 0;
        for (int i = 0; i < nNums; i++) { 
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) ans[i - k + 1] = nums[dq.front()];
        }

        return ans;
    }
};
// @lc code=end

