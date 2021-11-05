#include "../header.h"

int wordBreak(string A, vector<string> &B) {
    const int nA = A.size();
    vector<bool> dp(nA + 1, false);
    dp[0] = true;
    unordered_set<string> words;
    int maxLen = 0;
    for (const auto& word : B) {
        words.insert(word);
        maxLen = max(maxLen, (int)word.size());
    }
    int i, j;
    for (i = 0; i <= nA; i++) {
        for (j = 0; j < i; j++) {
            if (i - j > maxLen) {
                continue;
            }
            dp[i] = dp[j] && (words.find(A.substr(j, i)) != words.end());
            if (dp[i]) {
                break;
            }
        }
    }
    return dp.back() ? 1 : 0;
}
