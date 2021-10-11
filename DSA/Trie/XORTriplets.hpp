#include "../header.h"

#define m 1e9;
#define ll long long;

struct Node {
    unordered_map<int, Node*> children;
    ll idxSum = 0;
    ll cnt = 0;
};
void insert(Node* root, int xor, int idx) {
    int bit;
    for (int i = 31; i >= 0; i--) {
        auto& children = root->children;
        bit = (1 << i) & xor;
        if (children[bit] == children.end()) {
            children[bit] = new Node;
        }
        root = children[bit];
    }
    root->cnt++;
    root->idxSum += idx;
}

ll query(Node* root, int xor, int idx) {
    int bit;
    for (int i = 31; i >= 0; i--) {
        auto& children = root->children;
        bit = (1 << i) & xor;
        if (children[bit] == children.end()) {
            return 0;
        }
        root = children[bit];
    }
    return (root->cnt * idx - root->idxSum + m) % m;
}

int Solution::solve(vector<int> &A) {
    Node* root = new Node;
    int xor = 0;
    insert(root, xor, 0);
    ll ans = 0;
    int nA = A.size();
    for (int i = 0; i < nA; i++) {
        xor ^= A[i];
        ans = (ans + query(root, xor, i + 1)) % m;
        insert(root, xor, i + 1);
    }

    return ans;
}
