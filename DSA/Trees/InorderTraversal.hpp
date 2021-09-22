#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// void inorder(vector<int>& ans, TreeNode* root) {
//     if (!root) {
//         return;
//     }
//     inorder(ans, root->left);
//     ans.push_back(root->val);
//     inorder(ans, root->right);
// }
 
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    // inorder(ans, A);
    stack<TreeNode*> stk;
    auto* node = A;
    while (!stk.empty() || A) {
        if (A) {
            stk.push(A);
            A = A->left;
        } else {
            node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            A = node->right;
        }
    }
    
    return ans;
}
