#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > solve(vector<int> &A, vector<vector<int> > &B) {
    const int N = A.size();
    const int Q = B.size();
    
    vector<vector<int>> ans(Q, vector<int>(2));

    vector<int> prefixZeroCount;
    prefixZeroCount.reserve(N);
    int nZeros = 0;
    for (const int e : A) {
        if (e == 0) {
            nZeros++;
        }
        prefixZeroCount.push_back(nZeros);
    }

    int left, right;
    int xorAns;
    int nOnes;
    int i = 0;
    for (const auto& query : B) {
        left = query.front() - 1;
        right = query.back() - 1;

        if (left == 0) {
            nZeros = prefixZeroCount[right];
        } else {
            nZeros = prefixZeroCount[right] - prefixZeroCount[left - 1];
        }

        nOnes = (right - left + 1) - nZeros;
        xorAns = nOnes & 1;

        ans[i][0] = xorAns;
        ans[i][1] = nZeros;
        i++;
    }

    return ans;
}

int main() {
    vector<int> A = {1,0,0,0,1};
    vector<vector<int>> B = {
        {2,4},
        {1,5},
        {3,5}
    };
    auto ans = solve(A, B);
    for (const auto& e : ans) {
        cout << "[" << e[0] << ", " << e[1] << "]\n";
    }
    return 0;
}