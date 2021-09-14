#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findMiddle(ListNode* head) {
    auto* slow = head;
    auto* fast = head;

    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto* ans = slow->next;
    slow->next = nullptr;
    return ans;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    auto* cur = head;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* reorderList(ListNode* A) {
    auto* ptr1 = A;
    auto* ptr2 = findMiddle(A);
    ptr2 = reverseList(ptr2);
    auto* t1 = ptr1;
    auto* t2 = ptr2;
    while (ptr1 && ptr2) {
        t1 = ptr1->next;
        t2 = ptr2->next;
        
        ptr1->next = ptr2;
        ptr2->next = t1;

        ptr1 = t1;
        ptr2 = t2;
    }

    return A;
}