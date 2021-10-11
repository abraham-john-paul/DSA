#include "../header.h"

struct Node {
    unordered_map<int, Node*> children;
    int index = -1;
    Node(int idx) : index {idx} {}
};

void addToTrie(Node* root, int n, int idx) {
    int bit;
    for (int i = 31; i >= 0; i--) {
        bit = n & (1 << i);
        auto& children = root->children;
        if (children.find(bit) == children.end()) {
            children[bit] = new Node();
        }
        root = children[bit];
    }
    root->index = idx;
}

pair<int, int> findMaxXor(Node* root, int xor) {
    pait<int, int> ans;
    int bit;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        bit = n & (1 << i);
        ans <<= 1;
        auto& children = root->children;
        if (children.find(1 - bit) != children.end()) {
            root = children[1 - bit];
            ans &= (1 - bit);
        } else {
            root = children[bit];
            ans &= (bit);
        }
    }

    return {ans, root->index};
}

vector<int> Solution::solve(vector<int> &A) {
    int xorr = 0;
    int maxXor = 0;
    vector<int> ans(2);
    int n = A.size();
    pair<int, int> curMaxXor;

    Node* root = nullptr;
    addToTrie(root, xorr, -1);
    for (int i = 0; i < n; i++) {
        xor = xor ^ A[i];
        curMaxXor = findMaxXor(root, xor);
        
        if (curMaxXor.first > maxXor) {
            maxXor = curMaxXor.first;
            ans[0] = curMaxXor.second + 2;
            ans[1] = i + 1;
        }

        addToTrie(root, A[i], i);
    }

    return ans;
}