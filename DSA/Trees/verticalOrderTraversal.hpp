#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > verticalOrderTraversal(TreeNode* A) {
    unordered_map<int, vector<int>> um;
    queue<pair<TreeNode*, int>> q;
    int minVal = 0, maxVal = 0;
    if (A) {
        q.push({A, 0});
        um[0].push_back(A->val);
    }
    
    int n;
    while (!q.empty()) {
        n = q.size();
        
        for (int i = 0; i < n; i++) {
            auto p = q.front();
            q.pop();
            if (p.first->left) {
                minVal = min(minVal, p.second - 1);
                um[p.second - 1].push_back(p.first->left->val);
                q.push({p.first->left, p.second - 1});
            }
            
            if (p.first->right) {
                maxVal = max(maxVal, p.second + 1);
                um[p.second + 1].push_back(p.first->right->val);
                q.push({p.first->right, p.second + 1});
            }
        }
    }
    
    vector<vector<int>> ans(um.size());
    int i = 0;
    for (int j = minVal; j <= maxVal; j++) {
        ans[i++] = move(um[j]);
    }
    
    return ans;
}