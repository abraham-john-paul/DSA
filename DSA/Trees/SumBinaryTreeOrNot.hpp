#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkSumBinaryOrNot(TreeNode* root, bool& ans) {
    if (!root || !ans) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->val;
    }
    
    int sum = 0;
    sum += checkSumBinaryOrNot(root->left, ans);
    sum += checkSumBinaryOrNot(root->right, ans);
    
    ans &= (root->val == sum);
    
    return sum + root->val;
}
 
int solve(TreeNode* A) {
    bool ans = true;
    checkSumBinaryOrNot(A, ans);
    return ans;
}
