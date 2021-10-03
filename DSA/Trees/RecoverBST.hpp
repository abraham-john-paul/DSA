#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* prevNode = nullptr;
void traversal(TreeNode* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    traversal(root->left, ans);
    if (prevNode && prevNode->val > root->val && ans.size() == 0) {
        ans.push_back(prevNode->val);
    }
    if (prevNode && prevNode->val > root->val && ans.size() > 0) {
        if (ans.size() < 2) {
            ans.push_back(root->val);
        } else {
            ans.back() = root->val;
        }
    }
    prevNode = root;
    traversal(root->right, ans);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    prevNode = nullptr;
    traversal(A, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
