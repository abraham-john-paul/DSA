int Solution::minDepth(TreeNode* A) {
    if (!A) return 0;

    int left = minDepth(A->left) + 1;
    int right = minDepth(A->right) + 1;
    
    int depth = 1;
    if (right != 1 && left != 1) {
        depth = min(left, right);
    } else {
        depth = (left == 1) ? right : left;
    }

    return depth;
}