#include "../header.h"

void generateStrings(const unordered_map<char, string>& digitToLetterMap,
    vector<string>& ans, const string& digitString, 
    string curString, int pos) {
    if (pos == digitString.size()) {
        ans.push_back(curString);
        return;
    }

    const string curDigitMappedStr = digitToLetterMap.find(digitString[pos])->second;
    for (const auto & c : curDigitMappedStr) {
        generateStrings(digitToLetterMap, ans, digitString, curString + c, pos + 1);
    }
}

vector<string> letterCombinations(string A) {
    unordered_map<char, string> digitToLetterMap({
        {'0', "0"},
        {'1', "1"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}        
    });

    vector<string> ans;

    generateStrings(digitToLetterMap, ans, A, "", 0);

    return ans;
}