#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <math.h>

using namespace std;

void findDivisors(int A, vector<int>& divisors) {
    int n = sqrt(A);
    divisors.reserve(n);
    divisors.push_back(1);
    divisors.push_back(A);
    for (int i = 2; i  <= n; i++) {
        if (A % i == 0) {
            divisors.push_back(i);
            divisors.push_back(A / i);
        }
    }
}

vector<int> solve(const int A, const int B, const int C) {
    // vector<int> divisors;
    // findDivisors(C - B, divisors);
    // int n = 0;
    // int nLeft;
    // int d;
    // int minLast = INT_MAX;
    // int a;
    // int last;
    // for (const int divisor : divisors) {
    //     n = (C - B) / divisor + 1;
        
    //     if (n == A) {
    //         if (C < minLast) {
    //             d = divisor;
    //             a = B;
    //         }
    //         continue;
    //     } else if (n > A) {
    //         continue;
    //     } else {
    //         nLeft = A - n;
    //         int i = B;
    //         while (i >= 1 && nLeft > 0) {
    //             if (i - divisor < 1) {
    //                 break;
    //             }
    //             i -= divisor;
    //             nLeft--;
    //         }
    //         int k = ((C - i) / divisor + 1);
    //         last = i + (A - 1) * divisor;
    //         cout << "d " << d << "\n";
    //         cout << i << " " << last << " " << minLast << "\n";
    //         if (k < A && last < minLast) {
    //             minLast = last;
    //             a = i;
    //             d = divisor;
    //         }
    //     }
    // }

    // vector<int> vAP(A, 0);
    // for (int i = 0; i < A; i++) {
    //     vAP[i] = a + i * d;
    // }

    // return vAP;
    vector<int> divisors;
    findDivisors(C - B, divisors);
    int n;
    int nLeft;
    int d;
    int minLast = INT_MAX;
    int a;
    int last;
    for (const int divisor : divisors) {
        int i = C;
        nLeft = A;
        while (i >= B && nLeft > 0) {
            nLeft--;
            if(i == B || nLeft == 0) {
                break;
            }
            i -= divisor;
        }
        if (i == B) {
            for (; i >= 1 && nLeft > 0; i -= divisor) {
                nLeft--;
                if (i - divisor < 1) {
                    break;
                }
            }
            last = i + (A - 1) * divisor;
            if (last < minLast) {
                a = i;
                d = divisor;
                minLast = last;
            } else if (last == minLast && i < a) {
                a = i;
                d = divisor;
            }
        }
    }

    vector<int> vAP(A, 0);
    for (int i = 0; i < A; i++) {
        vAP[i] = a + i * d;
    }

    return vAP;
}


int main() {
    auto ans = solve(9, 1, 22);
    for (const int elem : ans) {
        cout << elem << " ";
    }
    return 0;
}