#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

string cardGame(const vector<int> &A) {
    unordered_map<int, int> um;
    for (const auto elem : A) {
        if(um.find(elem) == um.end()) {
            if(um.size() == 2) {
                return "LOSE";
            }
            um.insert({elem, 1});
        } else {
            um[elem]++;
        }
    }
    
    if(um.size() < 2) {
        return "LOSE";
    }

    auto itr2 = um.begin();
    auto itr1 = itr2++;
    
    return itr1->second == itr2->second ? "WIN" : "LOSE";
}

int main() {
    cout << cardGame({1, 1, 2 ,2 ,3 ,3 ,4, 4});
    return 0;
}