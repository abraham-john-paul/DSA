#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode* A) {
    queue<pair<TreeNode*, int>> q;
    unordered_map<int, int> distMap;
    if (A) {
        q.push({A, 0});
        distMap[0] = A->val;
    }
    int minDist = 0;
    
    while (!q.empty()) {
        auto& p = q.front();
        
        if (p.first->left) {
            q.push({p.first->left, p.second - 1});
            if (distMap.find(p.second - 1) == distMap.end()) {
                distMap[p.second - 1] = p.first->left->val;
                minDist = min(minDist, p.second - 1);
            }
        }
        
        if (p.first->right) {
            q.push({p.first->right, p.second + 1});
            if (distMap.find(p.second + 1) == distMap.end()) {
                distMap[p.second + 1] = p.first->right->val;
            }
        }
        
        q.pop();
    }
    
    vector<int> ans(distMap.size());
    int i = minDist;
    while (distMap.find(i) != distMap.end()) {
        ans[i - minDist] = distMap[i];
        i++;
    }
    return ans;
}