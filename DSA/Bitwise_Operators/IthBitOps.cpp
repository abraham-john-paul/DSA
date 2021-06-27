#include <iostream>

using namespace std;

int setIthBit(int M, int i) {
    return M | (1 << i);
}

int unsetIthBit(int M, int i) {
    return M & (~(1 << i));
}

int flipIthBit(int M, int i) {
    return M ^ (1 << i);
}

bool checkIfIthBitSet(int M, int i) {
    return (M >> i) & 1;
}

bool isOdd(int M) {
    return M & 1;
}

int removeLeastSignificantSetBit(int M) {
    return M & (M - 1);
}

bool isPowerOf2(int M) {
    return M && !(M & (M - 1));
}

int countSetBits(int N) { // O(set bits) Brian Kerninghan Algorithm
    int count = 0;

    while (N) {
        N &= (N - 1);
        count++;
    }

    return count;
}

int rightMostSetBit(int M) {
    // return M - (M & (M - 1));
    // return M & (~(M - 1));
    return (M ^ (M - 1)) & M;
}
 
int main() {
    int n = 7;
    int i = 2;
    cout << "n :" <<  n << "\n";

    cout << "setIthBit >> " <<  setIthBit(n, i)    << "\n";

    cout << "unsetIthBit >> " <<  unsetIthBit(n , i) << "\n";
    
    int ans = flipIthBit(n , i);
    cout << "flipIthBit >> " <<  ans  << "\n";
    cout << "flipIthBit >> " <<  flipIthBit(ans , i)  << "\n";
    
    cout << "checkIfIthBitSet >> " << boolalpha << checkIfIthBitSet(n , i + 1)  << "\n";

    cout << "IsOdd >> " << boolalpha << isOdd(n)  << "\n";
    cout << "IsOdd >> " << boolalpha << isOdd(n + 1)  << "\n";

    cout << "removeLeastSignificantSetBit >> " << boolalpha << removeLeastSignificantSetBit(n)  << "\n";

    cout << "isPowerOf2 >> " << boolalpha << isPowerOf2(n)  << "\n";
    cout << "isPowerOf2 >> " << boolalpha << isPowerOf2(n + 1)  << "\n";

    cout << "countSetBits >> " << boolalpha << countSetBits(n)  << "\n";
    cout << "countSetBits >> " << boolalpha << countSetBits(n + 1)  << "\n";

    cout << "rightMostSetBit >> " << boolalpha << rightMostSetBit(n)  << "\n";
    cout << "rightMostSetBit >> " << boolalpha << rightMostSetBit(n + 1)  << "\n";
    cout << "rightMostSetBit >> " << boolalpha << rightMostSetBit(n - 1)  << "\n";
    return 0;
}