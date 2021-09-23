#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int isSameTree(TreeNode* A, TreeNode* B) {
    queue<TreeNode*> qA;
    if (A) {
        qA.push(A);
    }
    TreeNode* nodeA = nullptr;
    
    queue<TreeNode*> qB;
    if (B) {
        qB.push(B);
    }
    TreeNode* nodeB = nullptr;
    bool foundLeft, foundRight;
    
    while(!qA.empty() && !qB.empty()) {
        nodeA = qA.front();
        qA.pop();
        
        nodeB = qB.front();
        qB.pop();
        
        if (nodeA->left) {
            qA.push(nodeA->left);
        }
        foundLeft = (bool)nodeA->left;
        
        if (nodeA->right) {
            qA.push(nodeA->right);
        }
        foundRight = (bool)nodeA->right;
        
        if (nodeB->left) {
            qB.push(nodeB->left);
        }
        
        if (nodeB->right) {
            qB.push(nodeB->right);
        }
        
        if ((foundRight != (bool)nodeB->right) ||
            (foundLeft != (bool)nodeB->left) ||
            (nodeA->val != nodeB->val)) {
            return false;
        }
    }
    
    return qA.size() == qB.size();
}