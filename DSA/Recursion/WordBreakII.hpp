#include "../header.h"

struct Node {
    char c;
    bool isLastChar;
    unordered_map<char, Node*> children;

    Node(char ch, bool isLast): 
        c{ch}, 
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

void backtrack(vector<string>& ans, vector<string>& words, 
    Node* root, Node * cur, int idx, 
    const string& A) {
    const int nA = A.size();
    if (idx == nA) {
        string sentence;
        const int nWords = words.size();
        for (int i = 0; i < nWords; i++) {
            sentence += words[i];
            if (i != (nWords - 1)) {
                sentence += " ";
            }
        }
        ans.push_back(sentence);
        return;
    }

    for (int i = idx; i < nA; i++) {
        if (cur->children.find(A[i]) != cur->children.end()) {
            if (cur->children[A[i]]->isLastChar) {
                words.push_back(A.substr(idx, i - idx + 1));
                backtrack(ans, words, root, root, i + 1, A);
                words.pop_back();
            }
            cur = cur->children[A[i]];
        } else {
            return;
        }
    }
}

vector<string> wordBreak(string A, vector<string> &B) {
    vector<string> ans;
    vector<string> words;
    Node* root = new Node{'/', false};
    
    for (const string& word : B) {
        addWord(root, word);
    }

    backtrack(ans, words, root, root, 0, A);
    
    return ans;
}
