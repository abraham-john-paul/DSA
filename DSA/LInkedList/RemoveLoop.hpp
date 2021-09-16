#include "../header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* solve(ListNode* A) {
    auto* slow = A;
    auto* fast = A;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    auto* ptr = A;
    if (slow == ptr) {
        while (slow->next != ptr) {
            slow = slow->next;
        }
    } else {
        while (slow->next != ptr->next) {
            ptr = ptr->next;
            slow = slow->next;
        }
    }

    slow->next = nullptr;
    return A;
}
