#include "../header.h"

string solve(string A) {
    queue<char> q;
    unordered_map<char, int> found;
    string B;
    B.reserve(A.size());
    
    for (char c : A) {
        found[c]++;
        if (found[c] == 1) {
            q.push(c);
        }
        while (!q.empty() && found[q.front()] != 1) {
            q.pop();
        }
        B += q.empty() ? '#' : q.front();
    }
    
    return B;
}