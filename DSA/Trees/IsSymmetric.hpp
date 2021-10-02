#include "../header.h"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

bool isTreeSymmetric(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) {
        return true;
    }
    if (!root1 || !root2 || (root1->val != root2->val)) {
        return false;
    }

    return isTreeSymmetric(root1->left, root2->right) && isTreeSymmetric(root1->right, root2->left);
}

int Solution::isSymmetric(TreeNode* A) {
    return (A == nullptr) && isTreeSymmetric(A->left, A->right);
}