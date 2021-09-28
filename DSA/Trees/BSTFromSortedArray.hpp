#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* makeBST(const vector<int> &A, int start, int end) {
    if (end < start) {
        return nullptr;
    }
    int mid = start + ((end - start) >> 1);
    auto* node = new TreeNode(A[mid]);
    node->left = makeBST(A, start, mid - 1);
    node->right = makeBST(A, mid + 1, end);
    return node;
}
 
TreeNode* sortedArrayToBST(const vector<int> &A) {
    return makeBST(A, 0, A.size() - 1);
}
