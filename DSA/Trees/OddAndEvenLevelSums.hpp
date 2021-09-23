#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode* A) {
    int level = 1;
    int evenSum = 0;
    int oddSum = 0;
    int sum = 0;
    
    queue<TreeNode*> q;
    if (A) {
        q.push(A);
    }
    
    auto* node = A;
    int i, n;
    while (!q.empty()) {
        n = q.size();
        for (i = 0; i < n; i++) {
            node = q.front();
            q.pop();
            
            sum += node->val;
            
            if (node->left) {
                q.push(node->left);
            }
            
            if (node->right) {
                q.push(node->right);
            }
        }
        
        if (level & 1) {
            oddSum += sum;
        } else {
            evenSum += sum;
        }
        
        sum = 0;
        level++;
    }
    
    return oddSum - evenSum;
}
