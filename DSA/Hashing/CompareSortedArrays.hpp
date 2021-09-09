#include "../header.h"

vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    unordered_map<int, int> um;
    const int nQ = B.size();
    vector<int> ans(nQ);
    
    int i, j;  
    int l1, r1, l2, r2;
    int n1, n2;

    const int nA = A.size();
    vector<int> prefixXor(nA + 1);
    partial_sum(A.begin(), A.end(), prefixXor.begin() + 1, [](int a, int b) { return a ^ b; });
    
    int xor1, xor2;
    for (i = 0; i < nQ; i++) {
        l1 = B[i][0];
        r1 = B[i][1];
        n1 = r1 - l1 + 1;

        l2 = B[i][2];
        r2 = B[i][3];
        n2 = r2 - l2 + 1;
        
        if (l1 == l2 && r1 == r2) {
            ans[i] = 1;
            continue;
        }

        if (n1 == n2) {
            xor1 = prefixXor[r1 + 1] ^ prefixXor[l1];
            xor2 = prefixXor[r2 + 1] ^ prefixXor[l2];

            if (xor1 == xor2) {
                for (j = l1; j <= r1; j++) {
                    um[A[j]]++;
                }

                for (j = l2; j <= r2; j++) {
                    if (um.find(A[j]) != um.end()) {
                        um[A[j]]--;
                        if (um[A[j]] == 0) {
                            um.erase(A[j]);
                        }
                    } else {
                        break;
                    }
                }
                
                if (um.empty()) {
                    ans[i] = 1;
                }
                um.clear();
            }
        }
    }
    
    return ans;
}
