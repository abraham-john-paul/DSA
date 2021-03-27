#include <iostream>
#include <queue>
#include <map>
#include <utility>
#include <limits.h>

using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int i) : data{i} {}
};

namespace tree {
    auto max = [](int a, int b) {
        return (a > b) ? a : b;
    };

    auto min = [](int a, int b) {
        return (a < b) ? a : b;
    };

    auto abs = [](int a) {
        return (a < 0) ? (-1 * a) : a;
    };
}

void appendToQueue(queue<Node*>& q) {
    Node* root = q.front();
    if (root->left) {
        q.push(root->left);
    }
    if (root->right) {
        q.push(root->right);
    }
    q.pop();
}

int getMax(Node* root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    return tree::max(root->data, tree::max(getMax(root->left), getMax(root->right)));
}

int getMin(Node* root) {
    if(!root) return -1;
    queue<Node*> q;
    int min = INT_MAX;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        min = tree::min(min, root->data);
        appendToQueue(q);
    }
    return min;
}

void printLevelByLevel(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    int i;
    int count;
    while (!q.empty()) {
        count = q.size();
        for (i = 0; i < count; i++) {
            cout << q.front()->data << " ";
            appendToQueue(q);
        }
        cout << "\n";
    }
}

void printLeftViewOfTree(Node* root, int level) {
    static int max_level = 0;
    if (!root) {
        return;
    }
    if(max_level < level) {
        cout << root->data << " ";
        max_level = level;
    }
    printLeftViewOfTree(root->left, level + 1);
    printLeftViewOfTree(root->right, level + 1);
}

void printLeftViewOfTree(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    int n;
    int i;
    while (!q.empty()) {
        n = q.size();
        cout << q.front()->data << " ";
        for(i = 0; i < n; i++) {
            appendToQueue(q);
        }
    }
}

void printRightView(Node* root, int level) {
    static int max_level = 0;
    if(!root) return;
    if(max_level < level) {
        cout << root->data << " ";
        max_level = level;
    }
    printRightView(root->right, level + 1);
    printRightView(root->left, level + 1);
}

void printRightView(Node* root) {
    if(!root) return;
    int i;
    queue<Node*> q;
    q.push(root);
    int n;

    while(!q.empty()) {
        n = q.size();
        for(i = 0; i < (n - 1); i++) {
            appendToQueue(q);
        }
        cout << q.front()->data << " ";
        appendToQueue(q);
    }
}

void printTopView(Node* root) {
    if (!root) {
        return;
    }
    map<int, int>  mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int n;
    int i;
    while (!q.empty()) {
        // cout << " " << q.front()->data << " " << q.back()->data;
        n = q.size();
        for (i = 0; i < n; i++) {
            auto node = q.front();
            if (mp.find(node.second) == mp.end()) {
                mp.insert({node.second, node.first->data});
            }
            if(node.first->left) {
                q.push({node.first->left, node.second - 1});
            }
            if(node.first->right) {
                q.push({node.first->right, node.second + 1});
            }
            q.pop();
        }
    }
    vector<int> topView;
    for(const auto& node : mp) {
        topView.push_back(node.second);
        cout << node.second << " ";
    }

}

// To check the value of root is equal to root for all the subtrees in the given tree
bool checkChildrenSumProperty(Node* root) {
    if (!root || (!root->left && !root->right)) {
        return true;
    }
    int sum = 0;
    if (!root->left) {
        sum += root->left->data;
    }
    if (!root->right) {
        sum += root->right->data;
    }
    return root->data == sum && 
        checkChildrenSumProperty(root->left) && 
            checkChildrenSumProperty(root->right);
}

int heightOfTree(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + tree::max(heightOfTree(root->left), heightOfTree(root->right));
}

/*
 * A tree is balanced if the difference of height of left and right subtrees is atmost one.
 */
bool checkBalancedTree_Naive(Node* root) {
    if (!root || (!root->left && !root->right)) {
        return true;
    }
    int leftHeight = heightOfTree(root->right);
    int rightHeight = heightOfTree(root->right);
    return (tree::abs(leftHeight - rightHeight) <= 1) && 
        checkBalancedTree_Naive(root->left) && 
            checkBalancedTree_Naive(root->right);
}

int isTreeBalanced(Node* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = isTreeBalanced(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = isTreeBalanced(root->right);
    if (rightHeight == -1) {
        return -1;
    }
    if (tree::abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return 1 + tree::max(isTreeBalanced(root->left), isTreeBalanced(root->right));
}

int maxWidthOfTree(Node* root) {
    if(!root) return 0;
    queue<Node*> q;
    q.push(root);
    int maxWidth = INT_MIN;
    int n;
    int i;
    while (!q.empty()) {
        n = q.size();
        maxWidth = tree::max(maxWidth, n);
        for (i = 0; i < n; i++) {
            appendToQueue(q);
        }
    }
    return maxWidth;
}

Node* treeToDLL(Node* root) {
    static Node* prev = nullptr;
    if(!root) {
        return root;
    }
    Node* head = treeToDLL(root->left);
    if(!prev) {
        head = root; 
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    treeToDLL(root->right);
    return root; 

}

void deleteTree(Node* root) {
    if(root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    cout << root->data << " ";
    delete root;
}

int main() {
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    printLevelByLevel(root);

    cout << "max of tree : " << getMax(root);

    cout << "\nmin of tree : " << getMin(root);

    cout << "\nleft view of tree : "; 
    printLeftViewOfTree(root, 1);

    cout << "\nleft view of tree  without recursion: "; 
    printLeftViewOfTree(root);

    cout << "\nright view of tree: "; 
    printRightView(root, 1);

    cout << "\nright view of tree  without recursion: "; 
    printRightView(root);

    cout << "\ntop view of tree  without recursion: "; 
    printTopView(root);

    cout << "\nDeleting tree...\n";
    deleteTree(root);
    
    return 0;
}
