#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    
    auto* leftRoot = dfs(root->left);
    auto* rightRoot = dfs(root->right);
    auto* cur = root;
    
    cur->right = leftRoot;
    if (cur->right) {
        cur = leftRoot->left;
        leftRoot->left = nullptr;
    }
    
    cur->right = rightRoot;
    if (cur->right) {
        cur = rightRoot->left;
        rightRoot->left = nullptr;
    }
    
    root->left = cur;
    return root;
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    A = dfs(A);
    A->left = nullptr;
    return A;
}