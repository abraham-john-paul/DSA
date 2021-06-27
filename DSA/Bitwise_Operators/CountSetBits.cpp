#include <iostream>

using namespace std;

int naive(int N) { // O(logN)
    int count = 0;

    while (N) {
        if (N & 1) {
            count++;
        }
        N >>= 1;
    }

    return count;
}

int optimal(int N) { // O(set bits) Brian Kerninghan Algorithm
    int count = 0;

    while (N) {
        N &= (N - 1);
        count++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << naive(n);
    cout << "\n";
    cout << optimal(n);
    return 0;
}