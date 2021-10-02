#include "../header.h"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    if (A) {
        q.push(A);
    }
    
    auto* node = A;
    auto* last = A;
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
        if (node != last) {
            node->next = q.front();
        } else {
            last = q.back();
        }
    }
}
