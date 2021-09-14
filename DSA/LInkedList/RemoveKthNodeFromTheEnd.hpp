#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* prev, ListNode* head) {
    if (prev == nullptr || head == nullptr) {
        return nullptr;
    }
    ListNode* temp = nullptr;
    if (prev == head) {
        temp = head;
        head = head->next;
    } else {
        if (prev->next == nullptr) {
            return head;
        }
        temp = prev->next;
        prev->next = prev->next->next;
    }
    delete temp;
    return head;
}

ListNode* removeNthFromEnd(ListNode* A, int B) {
    auto* ptr1 = A;
    int i = 0;
    while (i < B && ptr1 != nullptr) {
        ptr1 = ptr1->next;
        i++;
    }
    
    auto* ptr2 = A;
    auto* prev = A;
    while (ptr1 != nullptr) {
        prev = ptr2;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    A = deleteNode(prev, A);

    return A;
}
