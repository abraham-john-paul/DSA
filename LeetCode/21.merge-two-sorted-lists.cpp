/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addNode(ListNode* cur, ListNode* newNode) {
        if (!newNode) return nullptr;
        if (cur) {
            cur->next = newNode;
        }
        return newNode;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = ((list1 && list2 && list1->val <= list2->val) || !list2) ? list1 : list2;
        ListNode* itr = nullptr;
        while (list1 && list2) {
            if (list1->val <= list2->val) {                
                itr = addNode(itr, list1);
                list1 = list1->next;
            } else {
                itr = addNode(itr, list2);
                list2 = list2->next;
            }
        } 
        while (list1) {
            itr = addNode(itr, list1);
            list1 = list1->next;
        }
        while (list2) {
            itr = addNode(itr, list2);
            list2 = list2->next;
        }

        return head;
    }
};
// @lc code=end

