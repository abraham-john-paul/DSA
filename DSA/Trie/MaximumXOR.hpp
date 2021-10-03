#include "../header.h"

int countBits(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n >>= 1;
    }
    return cnt;
}

struct Node {
    unordered_map<int, Node*> children;
};

void convertToBits(int n, const int nBits, stack<int>& stk) {
    int cnt = 0;
    stk.clear();
    while (n > 0) {
        cnt++;
        stk.push(n & 1);
        n >>= 1;
    }
    if (cnt < nBits) {
        stk.push(0);
        cnt++;
    }
}

void addToTrie(Node* root, stack<int> stk) {
    stack<int> stk;
    convertToBits(n , nBits, stk);
    int e;
    while (!stk.empty()) {
        e = stk.top();
        stk.pop();
        auto& children = root->children;
        if (children.find(e) == children.end()) {
            children(e) = new Node();
        }
        root = children(e);
    }
}

int searchMaxXOR(Node* root, stack<int> stk) {
    int e;
    if (root->children.empty()) {
        return INT_MIN;
    }
    int ans = 0;
    while (!stk.empty()) {
        e = stk.top();
        stk.pop();
        auto& children = root->children;
        if (children.find(abs(e - 1)) == children.end()) {
            ans |= 1;
            children(e) = new Node();
            root = children(abs(e - 1));
        } else {
            root = children(e);
        }
        ans <<= 1; 
    }

    return ans;
}

int solve(vector<int> &A) {
    const int maxA = *max_element(A.begin(), A.end());
    const int nBits = countBits(maxA);
    
    auto* root = new Node();
    int ans = A.front();
    stack<int> stk;
    
    for (int e : A) {
        convertToBits(e , nBits, stk);
        ans = max(ans, searchMaxXOR(root, stk));
        addToTrie(root, stk);
        stk.clear();
    }

    return ans;
}
