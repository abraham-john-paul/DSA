#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* A, int B) {
    ListNode* tailLessThanB = nullptr;
    ListNode* headLessThanB = nullptr;
    auto* prev = A;
    while (A && A->val < B) {
        if (!headLessThanB) {
            headLessThanB = A;
            tailLessThanB = A;
        } else {
            tailLessThanB->next = A;
            tailLessThanB = A;
        }
        prev = A;
        A = A->next;
    }
    
    auto* headGreaterThanOrEqualToB = A;
    auto* ptr = A;
    while (ptr) {
        if (ptr->val < B) {
            if (!headLessThanB) {
                headLessThanB = ptr;
                tailLessThanB = ptr;
            } else {
                tailLessThanB->next = ptr;
                tailLessThanB = ptr;
            }
            prev->next = ptr->next;
        } else {
            prev = ptr;
        }
        ptr = ptr->next;
    }

    if (tailLessThanB) {
        tailLessThanB->next = headGreaterThanOrEqualToB;
    } else {
        headLessThanB = A;
    }

    return headLessThanB;
}