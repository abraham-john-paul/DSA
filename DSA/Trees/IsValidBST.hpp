#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using pii = pair<int, int>;
pii validateBST(TreeNode* root, bool& isValid) {
    if (!isValid || !root) {
        return {INT_MIN, INT_MAX};
    }
    pii pLeft = validateBST(root->left, isValid);
    pii pRight = validateBST(root->right, isValid);
    if (root->val <= pLeft.first || root->val > pRight.second) {
        isValid &= false;
    }
    return {max(root->val, pRight.first), min(root->val, pLeft.second)};
}
int isValidBST(TreeNode* A) {
    bool isValid = true;
    validateBST(A, isValid);
    return isValid;
}
