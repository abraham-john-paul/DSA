#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int isValidSudoku(const vector<string> &A) {
    int boxTop, boxBottom;
    int boxLeft, boxRight;

    unordered_set<char> us;
    auto itr = us.begin();
    
    int iRow = 0;
    do {
        for (const char c : A[iRow]) {
            if(c != '.') {
                itr = us.find(c);
                if (itr != us.end()) {
                    return 0;
                } else {
                    us.insert(c);
                }
            }
        }
        us.clear();
    } while (++iRow < 9);

    int iCol = 0;
    int i;
    do {
        for (i = 0; i < 9; i++) {
            if(A[i][iCol] != '.') {
                itr = us.find(A[i][iCol]);
                if (itr != us.end()) {
                    return 0;
                } else {
                    us.insert(A[i][iCol]);
                }
            }
        }
        us.clear();
    } while (++iCol < 9);

    int iBox = 0;
    int j;
    do {
        boxTop = (iBox / 3) * 3;
        boxBottom = boxTop + 3;
        boxLeft = (iBox % 3) * 3;
        boxRight = boxLeft + 3;

        for (i = boxTop; i < boxBottom; i++) {
            for (j = boxLeft; j < boxRight; j++)
                if (A[i][j] != '.') {
                    itr = us.find(A[i][j]);
                    if (itr != us.end()) {
                        return 0;
                    } else {
                        us.insert(A[i][j]);
                    }
                }
        }
        us.clear();
    } while (++iBox < 9);

    return 1;  // valid
}

int main() {
    vector<string> v = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};

    cout << isValidSudoku(v);
    // auto res = findPairs(v, b);
    // if (!res.empty()) {
    //     cout << res.front() << " " << res.back();
    // } else {
    //     cout << "Pair not found";
    // }
    return 0;
}