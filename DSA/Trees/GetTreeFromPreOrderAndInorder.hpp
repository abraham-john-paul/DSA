#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* makeTree(const vector<int> &A, const vector<int> &B,
    int start, int end, int pos) {
        if (end < start) {
            return nullptr;
        }
        int rootValue = A[pos];
        auto* root = new TreeNode(rootValue);
        int rootIdx = find(B.begin() + start, B.begin() + end + 1, rootValue) - B.begin();

        root->left = makeTree(A, B, start, rootIdx - 1, pos + 1);
        root->right = makeTree(A, B, rootIdx + 1, end, pos + rootIdx - start + 1);
        return root;
}


TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    return makeTree(A, B, 0, A.size() - 1, 0);
}