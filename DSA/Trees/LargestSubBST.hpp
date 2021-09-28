#include "../header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root, unordered_map<TreeNode*, int>& nodeCountMap) {
    if (root == nullptr) {
        return 0;     
    }
    int leftCount = 0;
    if (root->left) {
        leftCount = countNodes(root->left, nodeCountMap);
    }
    int rightCount = 0;
    if (root->right) {
        rightCount = countNodes(root->right, nodeCountMap);
    }
    nodeCountMap[root] = 1 + leftCount + rightCount;
    return nodeCountMap[root];
}

using pii = pair<int, int>;
pii largestBSTSubtree(TreeNode* root, int& ans, const unordered_map<TreeNode*, int>& nodeCountMap) {
    if (!root) {
        return {INT_MAX, INT_MIN};
    }
    
    pii pLeft = largestBSTSubtree(root->left, ans, nodeCountMap);
    pii pRight = largestBSTSubtree(root->right, ans, nodeCountMap);
    if (root->val >= pLeft.second && root->val < pRight.first) {
        ans = max(ans, nodeCountMap.at(root));
        return {max(root->val, pLeft.second), min(root->val, pRight.first)};
    }
    return {INT_MIN, INT_MAX};
}
 
int solve(TreeNode* A) {
    unordered_map<TreeNode*, int> nodeCountMap;
    countNodes(A, nodeCountMap);

    int ans = 0;
    largestBSTSubtree(A, ans, nodeCountMap);
    return ans;
}
