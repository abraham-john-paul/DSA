/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = 0;
        vector<vector<int>> ans;
        const int nIntervals = intervals.size();
        int l1, r1, l2, r2;
        while (end < nIntervals) {
            l1 = intervals[end][0];
            r1 = intervals[end][1];
            end++;
            while (end < nIntervals) {
                l2 = intervals[end][0];
                r2 = intervals[end][1];
                if (l1 <= l2 && l2 <= r1) {
                    r1 = max(r1, r2);
                } else {
                    break;
                }
                end++;
            }
            ans.push_back({l1, r1});
        }

        return ans;
    }
};
// @lc code=end

