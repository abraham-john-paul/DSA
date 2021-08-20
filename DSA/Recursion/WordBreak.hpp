#include "../header.h"

void backtrack(vector<string>& ans, vector<int>& spaces, int idx,
    const string& A, const unordered_set<string>& words) {
        if (idx == A.size()) {
            int start = spaces.back();
            if (words.find(A.substr(start)) != words.end()) {
                string sentence;
                int i = 0;
                for (const int sIdx : spaces) {
                    sentence += A.substr(i, sIdx - i);
                    sentence += " ";
                    i = sIdx;
                }
            }
        }
    }

vector<string> wordBreak(string A, vector<string> &B) {
    unordered_set<string> words;
    for (const auto& word : B) {
        words.insert(word);
    }
}