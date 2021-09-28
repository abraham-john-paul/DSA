#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void copyStack(stack<TreeNode*>& stk, vector<TreeNode*>& A) {
    A.reserve(stk.size());
    while (!stk.empty()) {
        A.push_back(stk.top());
        stk.pop();
    }
    reverse(A.begin(), A.end());

    for (auto node : A) {
        stk.push(node);
    }
}

bool preOrder(TreeNode* root, stack<TreeNode*>& stk, vector<TreeNode*>& pathToB, vector<TreeNode*>& pathToC, int B, int C) {
    if (!root) {
        return false;
    }
    stk.push(root);
    if (root->val == B) {
        copyStack(stk, pathToB);
    }
    if (root->val == C) {
        copyStack(stk, pathToC);
    }
    if (!pathToB.empty() && !pathToC.empty()) {
        return true;
    }
    if (preOrder(root->left, stk, pathToB, pathToC, B, C)) {
        return true;
    }
    if (preOrder(root->right, stk, pathToB, pathToC, B, C)) {
        return true;
    }
    stk.pop();
    return false;
}

 
int lca(TreeNode* A, int B, int C) {
    vector<TreeNode*> pathToB, pathToC;
    stack<TreeNode*> stk;
    preOrder(A, stk, pathToB, pathToC, B, C);

    
    int n = min(pathToB.size(), pathToC.size());
    int ans = -1;
    for (int i = 0; i < n; i++) {
        // cout << pathToB[i]->val << " " << pathToC[i]->val << endl;
        if (pathToB[i]->val != pathToC[i]->val) {
            break;
        }
        ans = pathToB[i]->val;
    }
    
    return ans;
}
