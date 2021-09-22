#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void postOrder(vector<int>& ans, TreeNode* root) {
    if (!root) {
        return;
    }
    postOrder(ans, root->left);
    postOrder(ans, root->right);
    ans.push_back(root->val);
} 

vector<int> postorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    // postOrder(ans, A);
    stack<pair<TreeNode*, int>> stk;
    stk.push({A, 0});
    
    while (!stk.empty()) {
        auto& p = stk.top();
        if (!p.first) {
            stk.pop();
            continue;
        }
        switch (p.second) {
            case 0:
                stk.push({p.first->left, 0});
                break;
            case 1:
                stk.push({p.first->right, 0});
                break;
            case 2:
                ans.push_back(p.first->val);
                break;
            default:
                stk.pop();
        }
        p.second++;
    }
    
    return ans;
}
