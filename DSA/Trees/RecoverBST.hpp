#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* last = nullptr;
    
public:
    void inOrder(TreeNode* root) {
        if (!root) return;
        
        inOrder(root->left);
        
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                last = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        
        inOrder(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        if (!root) return;
        
        prev = nullptr;
        first = nullptr;
        last = nullptr;
        
        inOrder(root);
        
        swap(first->val, last->val);
    }
};
