#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool dfs(TreeNode* root, int curSum, const int targetSum) {
    if (!root) {
        return false;
    }
    
    curSum += root->val;
    if (!root->left && !root->right) {
        return (curSum == targetSum);
    }
    
    if (dfs(root->left, curSum, targetSum)) {
        return true;
    }
    if (dfs(root->right, curSum, targetSum)) {
        return true;
    }
    
    return false;
}
 
int hasPathSum(TreeNode* A, int B) {
    return dfs(A, 0, B) ? 1 : 0;
}