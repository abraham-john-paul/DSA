#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int A, vector<vector<int> > &B) {
    vector<int> res(A);
    for (const auto w : B) {
        res[w[0] - 1] += w[2];
        if (w[1] != A) {
            res[w[1]] -= w[2];
        }
    }
    for (int i = 1; i < A; i++) {
        res[i] += res[i - 1];
    }

    return res;
}


int main() {
    int N = 5;
    vector<vector<int>> B =  {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    auto res = solve(N, B);
    for (const auto m : res) {
        cout << m << " ";
    }
    return 0;
}