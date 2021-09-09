#include "../header.h"

vector<int> solve(vector<vector<int> > &A) {
    const int nOps = A.size();
    vector<int> ans(nOps);
    int op, x;
    
    map<int, stack<int>> stMap;
    unordered_map<int, int> freqMap;
    int freq;

    for (int i = 0; i < nOps; i++) {
        op = A[i].front();
        switch(op) {
            case 1: {
                x = A[i].back();
                freqMap[x]++;
                freq = freqMap[x];
                stMap[freq].push(x);
                ans[i] = -1;
                break;
            } 
            case 2: {
                auto itr = stMap.rbegin();
                x = itr->second.top();
                freqMap[x]--;
                itr->second.pop();
                if (itr->second.empty()) {
                    stMap.erase(itr->first);
                }
                ans[i] = x;
                break;
            }
        }
    }

    return ans;
}
