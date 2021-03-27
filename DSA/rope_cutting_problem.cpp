#include <iostream>
#include <algorithm>

using namespace std;

int rope_cutting_problem(int n, int a, int b, int c) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    int res =  max(rope_cutting_problem(n - a, a, b, c),
        max(rope_cutting_problem(n - b, a, b, c), 
            rope_cutting_problem(n - c,a, b, c)));
    if (res == -1) {
        return -1;
    }
    return res + 1;
}

int main() {
    cout << rope_cutting_problem(9, 2, 2, 2);
    return 0;
}