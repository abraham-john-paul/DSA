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
    
    return slow;
} 

ListNode* reverse(ListNode* head) {
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

bool validatePalindrome(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) {
        return true;
    }
    while (head1->next && head1->next != head2->next) {
        if (head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return head1->val == head2->val;
}
 
int lPalin(ListNode* A) {
    auto* middle = findMiddle(A);
    auto* head2 = reverse(middle->next);
    auto *itr2 = head2;
    
    
    while (itr2) {
        if (!itr2->next) {
            itr2->next = middle;
            middle->next = nullptr;
        }
        itr2 = itr2->next;
    }
    
    return validatePalindrome(A, head2);
}