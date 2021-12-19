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
public:
    int findLeftMostValue(TreeNode* root) {      
        while (root->left) {
            root = root->left;
        }
        
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        
        if (root->val == key) {
            auto* temp = (TreeNode*)nullptr;
            if (!root->left && !root->right) {
                delete root;
            } else if (!root->left || !root->right) {
                temp = !root->left ? root->right : root->left;
                delete root;
            } else {
                root->val = findLeftMostValue(root->right);
                root->right = deleteNode(root->right, root->val);
                temp = root;
            }
            
            return temp;
        }
        
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        
        root->left = deleteNode(root->left, key);
        
        return root;
    }
};