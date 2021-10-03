struct Node {
    bool isEnd;
    unordered_map<char, Node*> children;
    Node(bool isEndingHere = false) : isEnd {isEndingHere} {}
};

bool addToTrie(Node* root, const string& s) {
    if (!root) {
        return false;
    }

    int nS = s.size();
    for (int i = 0; i < nS; i++) {
        auto& children = root->children;
        if (children.find(s[i]) == children.end()) {
            children[s[i]] = new Node();
        }
        root = children[s[i]];
    }
    root->isEnd = true;

    return true;
}

bool deleteFromTrie(Node* root, const string& s, int idx, bool& toBeDeleted) {
    if (!root) {
        return false;
    }

    if (idx == s.size()) {
        root->isEnd = false;
        if (root->children.empty()) {
            delete root;
            toBeDeleted = true;
        } else {
            toBeDeleted = false;
        }
        return true;
    }

    if (root->children.find(s[idx]) != root->children.end()) {
        if (deleteFromTrie(root->children[s[idx]], s, idx + 1, toBeDeleted)) {
            if (toBeDeleted) {
                root->children.erase(s[idx]);
                if (root->children.empty()) {
                    delete root;
                    toBeDeleted = true;
                } else {
                    toBeDeleted = false;
                }
            }
        }
    } else {
        return false;
    }
        
    return true;
}

bool searchInTrie(Node* root, const string& s) {
    if (!root) {
        return false;
    }

    int nS = s.size();
    for (int i = 0; i < nS; i++) {
        auto& children = root->children;
        if (children.find(s[i]) == children.end()) {
            return false;
        }
        root = children[s[i]];
    }

    return root->isEnd;
}

vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    auto* root = new Node();

    for (const auto& wordA : A) {
        addToTrie(root, wordA);
    }
    vector<int> ans;
    ans.reserve(B.size());

    for (const auto& wordB : B) {
        ans.push_back((searchInTrie(root, wordB) ? 1 : 0));
    }

    for (const auto& wordA : A) {
        bool toBeDeleted = false;
        deleteFromTrie(root, wordA, 0, toBeDeleted);
    }

    return ans;
}