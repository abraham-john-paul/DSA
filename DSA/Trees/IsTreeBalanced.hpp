#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int height(int& ans, TreeNode* root) {
    if (!root || ans == 0) {
        return -1;
    }
    
    int left = 0;
    if (root->left) {
        left = height(ans, root->left);
    }
    
    int right = 0;
    if (root->right) {
        right = height(ans, root->right);
    }
    ans = (abs(left - right) <= 1) ? 1 : 0;
    return max(left, right) + 1;
}
 
 
int isBalanced(TreeNode* A) {
    int ans = 1;
    height(ans, A);
    return ans;
}