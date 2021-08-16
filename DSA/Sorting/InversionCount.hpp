#include "../header.h"

void merge(vector<int> &A, int start, int mid, int end, long long& ans) {
    const int m = 1000000007;
    vector<int> left(A.begin() + start, A.begin() + mid + 1);
    int l = 0;
    int nL = mid - start + 1;
    
    vector<int> right(A.begin() + mid + 1, A.begin() + end + 1);
    int r = 0;
    
    int nR = end - mid;

    int a = start;

    while (l < nL && r < nR) {
        if (left[l] <= right[r]) {
            A[a] = left[l++];
            ans = (ans + r) % m;
        } else {
            A[a] = right[r++];
        }
        a++;
    }

    while (l < nL) {
        ans = (ans + r) % m;
        A[a++] = left[l++];
    }

    while (r < nR) {
        A[a++] = right[r++];
    }
}

void mergeSort(vector<int> &A, int start, int end, long long& ans) {
    if (start == end) {
        return;
    }

    int mid = start + ((end - start) / 2);
    mergeSort(A, start, mid, ans);
    mergeSort(A, mid + 1, end, ans);
    merge(A, start, mid, end, ans);
}

int solve(vector<int> &A) {
    long long ans = 0;
    mergeSort(A, 0, A.size() - 1, ans);

    return ans;
}
