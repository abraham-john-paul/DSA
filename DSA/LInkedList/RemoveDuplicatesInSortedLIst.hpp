#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A) {
    ListNode* temp = nullptr;
    while (A && A->next && A->val == A->next->val) {
        temp = A;
        A = A->next;
        delete temp;
    }
    auto* cur = A;
    auto* prev = A;
    while (cur) {
        if (cur->next && cur->val == cur->next->val) {
            while (cur && cur->next && cur->val == cur->next->val) {
                temp = cur;
                cur = cur->next;
                delete temp;
            }
            prev->next = cur;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return A;
}