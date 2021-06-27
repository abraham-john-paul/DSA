#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string largestNumber(const vector<int> &A) {
    vector<int> v(A.begin(), A.end());
    sort(v.begin(), v.end(), [](int a, int b) -> bool {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    });
    string res = "";
    
    for (const int e : A) {
        res += to_string(e);
    }
    
    return res;
}

int main() {
    vector<int> v = {3, 30, 34, 5, 9};
    cout << v.size() << endl;
    cout << largestNumber(v);

    return 0;
}