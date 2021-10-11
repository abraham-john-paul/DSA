#include "../header.h"

#define m int(1e9 + 7)
#define ll long long

struct Node {
    Node* one = nullptr;
    Node* zero = nullptr;
    int count = 0;
};

void insert(Node* root, int n) {
    int bit;
    for (int i = 31; i >= 0; i--) {
        bit = n & (1 << i);
        if (bit) {
            if (!root->one) {
                root->one = new Node();
            }
            root = root->one;
        } else {
            if (!root->zero) {
                root->zero = new Node();
            }
            root = root->zero;
        }
        root->count++;
    }
}

int query(Node* root, int xorr, const int B) {
    ll n = 0;
    int a, b;
    int bit;
    for (int i = 31; i >= 0; i--) {
        a = xorr & (1 << i);
        b = B & (1 << i);
        bit = a ^ b;
        if (bit) {
            if (!root->zero && !root->one) {
                return 0;
            }
            if (root->zero) {
                n += root->zero->count;
                root = root->zero;
            } 
            if (root->one) {
                root = root->one;
            }
        } else {
            if (!root->zero) {
                return 0;
            }
            root = root->zero;
        }
    }
    return (n * (n + 1) / 2) % m;
}

int Solution::solve(vector<int> &A, int B) {
    int xorr = 0;
    Node* root = new Node();
    ll ans = 0;

    for (int a : A) {
        xorr ^= a;
        ans = (ans + query(root, n, B)) % m;
        insert(root, a);    
    }

    return ans;
}
