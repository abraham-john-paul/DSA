#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    char c;
    bool isLastChar;
    unordered_map<char, Node*> children;

    Node(char ch, bool isLast)
    : c{ch}, 
      isLastChar{isLast} {}

};

void addWord(Node* root, string word) {
    if(word.empty()) {
        root->isLastChar = true;
        return;
    }
    char ch = word.at(0);
    Node* child = nullptr;
    if(root->children.find(ch) == root->children.end()) {
        child = new Node{ch, false};
        root->children[ch] = child;
    } else {
        child = root->children[ch];
    }
    addWord(child, word.substr(1));
}