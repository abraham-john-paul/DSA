#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* makeDLL(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    
    auto* leftRoot  = makeDLL(root->left);
    
    auto* head = leftRoot ? leftRoot : root;
    auto* cur = leftRoot ? leftRoot->left : root;

    if (leftRoot) {
        cur->right = root;
        root->left = cur;
    }
    
    cur = root;
    auto* rightRoot = makeDLL(root->right);
    
    head->left = rightRoot ? rightRoot->left : root;
    
    if (rightRoot) {
        cur->right = rightRoot;
        rightRoot->left = cur;
    }
    
    return head;
}

TreeNode* solve(TreeNode *A){
    auto* head = makeDLL(A);
    auto* tail = head ? head->left : head;

    if (head) {
        tail->right = head;
        head->left = tail;
    }
    
    return head;
}