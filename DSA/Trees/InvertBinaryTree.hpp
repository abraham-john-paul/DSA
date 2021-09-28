#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root) {
    if (!root) {
        return;
    }
    auto* left = root->left;
    auto* right = root->right;
    root->left = right;
    root->right = left;
    dfs(root->left);
    dfs(root->right);
}


TreeNode* Solution::invertTree(TreeNode* A) {
    dfs(A);
    return A;
}