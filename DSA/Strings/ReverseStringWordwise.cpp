#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void trimSpaces(string& A, int start, int end) {
    while (start < end) {
        if (A[end] != ' ') {
            break;
        }
        end--;
    }
    A = A.substr(start , end - start + 1);
    while (start < end) {
        if (A[start] != ' ') {
            break;
        }
        start++;
    }
    A = A.substr(start, end - start + 1);
}

string reverse(string& A, int start, int end) {
    int s = start;
    int e = end;
    while (start < end) {
        swap(A[start++], A[end--]);
    }
    return A.substr(s, e - s + 1);
}

string solve(string A) {
    const int n = A.size();
    string res;
    int start = 0; 
    int end = n - 1;
    trimSpaces(A, start, end);
    end = A.size() - 1;
    reverse(A, start, end);
    int i = 0;
    start = 0;
    while (i < A.size()) {
        if (A[i] == ' ') {
            end = i - 1;
            res += reverse(A, start, end);
            res += " ";
            while(A[i + 1] == ' ') {
                i++;
            }
            start = i + 1;
        }
        i++;
    }
    res += reverse(A, start, A.size() - 1);
    return res;
}

int main() {
    string s = "qxkpvo  f   w vdg t wqxy ln mbqmtwwbaegx   mskgtlenfnipsl bddjk znhksoewu zwh bd fqecoskmo";
    auto res = solve(s);
    cout << res;
    return 0;
}