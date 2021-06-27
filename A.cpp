// #include <iostream>
// #include "B.cpp"

// using  namespace std;

// namespace ccos {
//     namespace wifi {
//         void printName() {
//             cout << "\nccos::wifi >> Abraham John Paul";
//         }
//     }
// }

// int main() {
//     ccos::printName();
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     vector<int> v = {1, 2, 3, 4, 5};
//     if(auto itr = find(v.begin(), v.end(), 3);
//     itr != v.end()) {
//         cout << "\nFound 3 at " << itr - v.begin();
//     }
//     return 0;
// }

#include<initializer_list>
#include <iostream>
#include<vector>
class MagicFoo {public:std::vector<int> vec;
MagicFoo(std::initializer_list<int> list) : vec(list) {
    // for(std::initializer_list<int>::iterator it = list.begin();it != list.end(); ++it)
    // vec.push_back(*it);
    }
    };
    int main() {// after C++11
    MagicFoo magicFoo = {1,2,3,4,5};
    std::cout <<"magicFoo: ";
    for(std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) 
    std::cout << *it << std::endl;
    }