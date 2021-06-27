#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> subArrayWithGivenSum(vector<int> &A, int B) {
    unordered_map<long long int, int> um;
    long long int cumSum = 0;
    um.insert({cumSum, -1});
    const int n = A.size();
    auto itr = um.begin();
    for (int i = 0; i < n; i++) {
        cumSum += A[i];
        itr = um.find(cumSum - B);

        if (itr != um.end()) {
            return vector<int>(A.begin() + itr->second + 1, A.begin() + i + 1);
            break;
        }

        um.insert({cumSum, i});
    }

    return {-1};
}

int main() {
    vector<int> v = { 23, 50, 44, 6, 39, 15, 44, 27, 47, 29, 30, 44, 28, 42, 7, 32, 16, 40, 8, 7, 5, 48, 48, 16, 9, 5, 50, 16, 18, 9, 21, 26, 48, 37, 27, 7, 5, 29, 24, 28, 10, 44, 21, 1, 48, 15, 31, 41, 42, 23, 4, 32, 40, 40, 27, 20, 29, 42, 25, 18, 37, 43, 13, 30, 42, 24, 17, 42, 14, 42, 43, 36, 31, 29, 24, 24, 8, 3, 12, 34, 14, 6 };
    int b = 62;
    auto res = subArrayWithGivenSum(v, b);
    for(const auto elem : res) {
        cout << elem << " ";
    }
    return 0;
}