#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodesInPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    auto* prev = head;
    auto* cur = prev->next;
    auto* next = cur->next;
    cur->next = prev;
    head = cur;
    prev->next = swapNodesInPairs(next);
    return head;
}

ListNode* swapPairs(ListNode * head) {
    return swapNodesInPairs(head);
}