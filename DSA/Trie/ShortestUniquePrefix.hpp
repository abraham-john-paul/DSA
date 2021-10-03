#include "../header.h"

struct Node {
    int wordsContaining = 0;
    unordered_map<char, Node*> children;
};

void addToTrie(Node* root, const string& word, int i) {
    if (i == word.size()) {
        return;
    }
    auto& children = root->children;
    if (children.find(word[i]) == children.end()) {
        children[word[i]] = new Node();
    }
    children[word[i]]->wordsContaining++;
    addToTrie(children[word[i]], i + 1);
}

string searchUniquePrefix(Node* root, const string& s) {
    string ans;
    ans.reserve(s.size());
    for (char c : s) {
        ans += c;
        root = root->children[c];
        if (root->wordsContaining == 1) {
            break;
        }
    }
    return ans;
}

vector<string> prefix(vector<string> &A) {
    auto* root = new Node();
    for (auto& word : A) {
        addToTrie(root, word, 0);
    }
    vector<string> ans;
    ans.reserve(A.size());
    for (auto& word : A) {
        ans.push_back(searchUniquePrefix(root, word));
    }
    return ans;
}