#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findMaxSumPath(TreeNode* root, int& ans) {
    if (!root) {
        return 0;
    }

    int left = findMaxSumPath(root->left, ans);
    int right = findMaxSumPath(root->right, ans);
    int curMaxPath = max(max(left, right) + root->val, root->val);
    int curMaxSum = max(root->val + left + right, curMaxPath);
    ans = max(ans, curMaxSum);
    return curMaxPath;
}

int maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    findMaxSumPath(A, ans);
    return ans;
}
