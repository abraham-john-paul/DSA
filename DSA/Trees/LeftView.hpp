#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode* A) {
    queue<TreeNode*> q;
    vector<int> ans;
    if (A) {
        q.push(A);
        ans.push_back(A->val);
    }
    auto* last = A;
    auto* node = A;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        if (node->left) {
            q.push(node->left);
        }
        
        if (node->right) {
            q.push(node->right);
        }
        
        if (node == last) {
            if (!q.empty()) {
                ans.push_back(q.front()->val);
            }
            last = q.back();
        }
    }
    
    return ans;
}