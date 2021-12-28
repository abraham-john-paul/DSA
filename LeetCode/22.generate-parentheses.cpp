/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
    void generateParanthesis(vector<string>& ans, string& cur, const int n, int open, int closed) {
        if (open + closed == (n << 1)) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur += "(";
            generateParanthesis(ans, cur, n, open + 1, closed);
            cur.pop_back();
        }

        if (open - closed > 0 && closed < n) {
            cur += ")";
            generateParanthesis(ans, cur, n, open, closed + 1);
            cur.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> ans;
        generateParanthesis(ans, cur, n, 0, 0);
        return ans;
    }
};
// @lc code=end

