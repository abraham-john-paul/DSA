#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameter(TreeNode* root, int& dia) {
    if (!root) {
        return -1;
    }
    int leftHeight = diameter(root->left, dia);
    int rightHeight = diameter(root->right, dia);
    dia = max(dia, leftHeight + rightHeight + 2);
    return max(leftHeight, rightHeight) + 1;
}
 
int Solution::solve(TreeNode* A) {
    int dia = INT_MIN;
    diameter(A, dia);
    return dia;
}
