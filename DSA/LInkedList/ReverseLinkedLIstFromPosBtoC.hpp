#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    auto* prev = (ListNode*)nullptr;
    auto* next = (ListNode*)nullptr;
    auto* cur = head;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* reverseBetween(ListNode* A, int B, int C) {
    auto* prev = A;
    auto* cur = A;
    for (int i = 1; i < B; i++) {
        prev = cur;
        cur = cur->next;
    }
    auto* head = cur; 
    auto* tail = head;
    auto* next = cur->next;
    for (int i = B; i < C; i++) {
        cur = cur->next;
        next = cur->next;
    }
    cur->next = nullptr;
    head = reverseLinkedList(head);
    prev->next = head;
    tail->next = next;
    return A;
}
