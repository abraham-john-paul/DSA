class Solution {
public:
    int distributeCoins(TreeNode* root, int& minMoves) {
        if (!root) return 0;
        
        int leftNeed = distributeCoins(root->left, minMoves);
        int rightNeed = distributeCoins(root->right, minMoves);
        
        minMoves += (abs(leftNeed) + abs(rightNeed));
        
        return (root->val + leftNeed + rightNeed - 1);
    }
    
    int distributeCoins(TreeNode* root) {
        int minMoves = 0;
        
        distributeCoins(root, minMoves);
        
        return minMoves;
    }
};