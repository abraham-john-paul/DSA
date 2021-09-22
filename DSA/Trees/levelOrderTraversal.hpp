#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    if (A) {
        q.push(A);
    }
    vector<vector<int>> ans;
    vector<int> level;
    int n;
    
    while (!q.empty()) {
        n = q.size();
        level.reserve(n);
        
        for (int i = 0; i < n; i++) {
            auto* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        
        ans.push_back(level);
        level.clear();
    }
    
    return ans;
}