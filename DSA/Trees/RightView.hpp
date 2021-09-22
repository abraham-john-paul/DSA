#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

vector<int> solve(TreeNode* A) {
    queue<TreeNode*> q;
    if (A) {
        q.push(A);
    }
    
    vector<int> ans;
    auto* last = A;
    
    while (!q.empty()) {
        auto* node = q.front();
        q.pop();
        
        if (node->left) {
            q.push(node->left);
        }
        
        if (node->right) {
            q.push(node->right);
        }
        
        if (node == last) {
            ans.push_back(node->val);
            last = q.back();
        }
    }
    
    return ans;
}