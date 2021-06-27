#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextWarmerDay(vector<int>& v) {
    vector<int> res;
    res.reserve(v.size());
    stack<int> s;
    for (const auto& day : v) {
        
    }
}

int main() {
    vector<int> v = {60, 90, 76, 80, 100, 62, 90};
    auto res = nextWarmerDay(v);
    for(const auto& day : res) {
        cout << day << " ";
    }
    return  0;
}