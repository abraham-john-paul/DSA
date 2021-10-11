struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
};

void addToTrie(Node* root, int n) {
    int e;
    for (int i = 31; i >= 0; i--) {
        e = (n >> i) & 1;
        if (e) {
            if (!root->right) {
                root->right = new Node();
            }
            root = root->right;
        } else {
            if (!root->left) {
                root->left = new Node();
            }
            root = root->left;
        }
    }
}

int searchMaxXOR(Node* root, int n) {
    int ans = 0;
    int e;
    for (int i = 31; i >= 0; i--) {
        e = (n >> i) & 1;
        if (1 - e) {
            if (root->right) {
                ans |= (1 << i);
                root = root->right;
            } else {
                root = root->left;
            }
        } else {
            if (root->left) {
                ans |= (1 << i);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    return ans;
}

int Solution::solve(vector<int> &A) {
    auto* root = new Node();
    
    for (int e : A) {
        addToTrie(root, e);
    }
    
    int ans = INT_MIN;
    for (int e : A) {
        ans = max(ans, searchMaxXOR(root, e));
    }

    return ans;
}