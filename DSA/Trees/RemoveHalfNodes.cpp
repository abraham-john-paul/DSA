/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* traverse(TreeNode* root) {
    if (!root) return nullptr;
    
    root->left = traverse(root->left);
    root->right = traverse(root->right);

    if (root->left && !root->right) {
        auto* temp = root;
        root = root->left;
        delete temp;
    } else if (!root->left && root->right) {
        auto* temp = root;
        root = root->right;
        delete temp;
    }

    return root;
}

TreeNode* Solution::solve(TreeNode* A) {
    return traverse(A);
}