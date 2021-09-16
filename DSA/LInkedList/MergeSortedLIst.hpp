#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    auto* head = (ListNode*)nullptr;
    auto* tail = (ListNode*)nullptr;
    while (A && B) {
        if (A->val <= B->val) {
            if (!head) {
                head = new ListNode(A->val);
                tail = head;
            } else {
                tail->next = new ListNode(A->val);
                tail = tail->next;
            }
            A = A->next;
        } else {
            if (!head) {
                head = new ListNode(B->val);
                tail = head;
            } else {
                tail->next = new ListNode(B->val);
                tail = tail->next;
            }
            B = B->next;
        }
    }
    
    while (A) {
        if (!head) {
            head = new ListNode(A->val);
            tail = head;
        } else {
            tail->next = new ListNode(A->val);
            tail = tail->next;
        }
        A = A->next;
    }
    
    while (B) {
        if (!head) {
            head = new ListNode(B->val);
            tail = head;
        } else {
            tail->next = new ListNode(B->val);
            tail = tail->next;
        }
        B = B->next;
    }
    return head;
}