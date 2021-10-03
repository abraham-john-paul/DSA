#include "../header.h"

struct Node {
    int wordsContaining = 0;
    unordered_map<char, Node*> children;
};

void addContact(Node* root, const string& contact, int i) {
    if (i == contact.size()) {
        return;
    }
    auto& children = root->children;
    if (children.find(contact[i]) == children.end()) {
        children[contact[i]] = new Node();
    }
    children[contact[i]]->wordsContaining++;
    addContact(children[contact[i]], i + 1);
}

int prefixSearch(Node* root, const string& name) {
    for (char c : name) {
        auto& children = root->children;
        if (children.find(c) != children.end()) {
            root = children[c];
        } else {
            return 0;
        }
    }
    return root->wordsContaining;
}

void deleteTrie(Node* root) {
    if (root->children().empty()) {
        delete root;
        return;
    }
    auto& children = root->children;
    for (auto& child : children) {
        deleteTrie(child.second);
    }
    delete root;
}

vector<int> Solution::solve(vector<int> &A, vector<string> &B) {
    const int n = A.size();
    auto* root = new Node();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        switch(A[i]) {
            case 0: {
                addContact(root, B[i]);
                break;
            }
            case 1: {
                ans.push_back(prefixSearch(root, B[i]));
                break;
            }
        }
    }

    deleteTrie(root);

    return ans;
}