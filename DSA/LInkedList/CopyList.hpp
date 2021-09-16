#include "../header.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* A) {
    auto* ptr = A;
    auto* itr = A;

    while (itr != nullptr) {
        ptr = new RandomListNode(itr->label);
        ptr->next = itr->next;
        itr->next = ptr;
        itr = ptr->next;
    }
    
    itr = A;
    while (itr != nullptr) {
        ptr = itr->next;
        if (itr->random) {
            ptr->random = itr->random->next;
        }
        itr = ptr->next;
    }
    
    itr = A;
    auto* newHead = A->next;
    while (itr != nullptr) {
        ptr = itr->next->next;
        itr->next->next = (ptr) ? ptr->next : nullptr;
        itr->next = ptr;
        itr = itr->next;
    }

    return newHead;
}