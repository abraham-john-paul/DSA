#include "../header.h"

struct Node {
    bool isEnd = false;
    unordered_map<char, Node*> children;
};

void addToTrie(Node* root, const string& s) {
    for (char c : s) {
        auto& children = root->children;
        if (children.find(c) == children.end()) {
            children[c] = new Node();
        }
        root = children[c];
    }
    root->isEnd = true;
}

bool modifiedSearch(Node* root, const string& s, int nModifications, int i) {
    if (nModifications < 0) {
        return false;
    }
    if (i == s.size()) {
        return root->isEnd && (nModifications == 0);
    }
    auto& children = root->children;
    if (children.find(s[i]) != children.end()) {
        if (modifiedSearch(children[s[i]], s, nModifications, i + 1)) {
            return true;
        }
    }
    for (auto& child : children) {
        if (child.first != s[i] && modifiedSearch(child.second, s, nModifications - 1, i + 1)) {
            return true;
        }
    }
    return false;
}

void deleteTrie(Node* root) {
    if (root->children.empty()) {
        delete root;
        return;
    }
    for (auto& child : root->children) {
        deleteTrie(child.second);   
    }
    delete root;
}

string Solution::solve(vector<string> &A, vector<string> &B) {
    auto* root = new Node();
    for (auto& word : A) {
        addToTrie(root, word);
    }

    string ans;
    ans.reserve(B.size());
    
    for (auto& word : B) {
        c += modifiedSearch(root, word) ? "1" : "0";
    }

    deleteTrie(root);

    return ans;
}