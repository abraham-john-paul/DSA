#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    auto* prev = (ListNode*)nullptr;
    auto* cur = head;
    auto* next = (ListNode*)nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* reverseBNodes(ListNode* head, const int B) {
    if (head == nullptr) {
        return nullptr;
    }
    auto* next = (ListNode*)nullptr;
    auto* tail = head;
    for (int i = 1; i < B; i++) {
        tail = tail->next;
    }
    next = tail->next;
    tail->next = nullptr;
    tail = head;
    head = reverseLinkedList(head);
    tail->next = reverseBNodes(next, B);
    return head;

}

ListNode* reverseList(ListNode* A, int B) {
    return reverseBNodes(A, B);
}
