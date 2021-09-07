#include "../header.h"

vector<int> solve(vector<vector<int> > &A) {
    const int nOps = A.size();
    vector<int> ans(nOps);
    int i = 0;
    unordered_set<int> found;
    stack<pair<int, int>> st1, st2;
    int x;
    pair<int, int> maxFreq;
    for(const auto& op : A) {
        if (op.front() == 1) {
            x = op.back();
            if (found.find(x) == found.end()) {
                found.insert(x);
                st1.push({x, 1});
            } else {
                while (st1.top().first != x) {
                    auto p = st1.top();
                    st1.pop();
                    st2.push(p);
                }
                st1.top().second++;
                if (st1.top().second > maxFreq.second) {
                    maxFreq = st1.top();
                }
                while (!st2.empty()) {
                    auto p = st2.top();
                    st2.pop();
                    st1.push(p);
                }
                ans[i++] = -1;
            }
        } else {
            auto p = st1.top();
            st1.pop();
            if (p.first == maxFreq.first) {
                maxFreq.second--;
                while (!st1.empty()) {
                    if (st1.top().second == maxFreq.second) {
                        maxFreq.first = st1.top().first;
                    } else if (st1.top().second > maxFreq.second) {
                        maxFreq = st1.top();
                    }
                    st2.push(st1.top());
                    st1.pop();
                }
                while (!st2.empty()) {
                    auto p = st2.top();
                    st2.pop();
                    st1.push(p);
                }
            }
            ans[i++] = maxFreq.first;
        }
    }

    return ans;
}
