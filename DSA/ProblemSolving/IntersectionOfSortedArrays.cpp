#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    int iA = 0;
    const int nA = A.size();
    int iB = 0;
    const int nB = B.size();

    vector<int> ans;
    ans.reserve(nA + nB);

    while (iA < nA && iB < nB) {
        if (A[iA] < B[iB]) {
            iA++;
        } else if (A[iA] > B[iB]) {
            iB++;
        } else {
            ans.push_back(A[iA]);
            iA++;
            iB++;
        }
    }

    return ans;
}

int main() {
    vector<int> A = {1, 2, 3, 3, 4, 5, 6};
    vector<int> B = {3, 3, 5};
    
    auto ans = intersect(A, B);
    for (const int e : ans) {
        cout << e << " ";
    }

    return 0;
}
