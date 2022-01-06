/*
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]

Lets say N = size of the array. Then, following holds true :

- All elements in the array are in the range [0, N-1]
- N * N does not overflow for a signed integer

*/

void Solution::arrange(vector<int> &A) {
    const int n = A.size();
    // 0 1 2 3
    // 2 3 0 1
    // 2 7 10 13
    // 0 1 2 1
    for (int& i : A) {
        i = i + n * (A[i] % n);
    }

    for (int& i : A) {
        i /= n;
    }
}