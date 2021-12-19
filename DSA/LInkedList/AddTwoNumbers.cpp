struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int countNodes(ListNode* head) {
        int cnt = 0;
        
        while (head) {
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
    
    ListNode* addLists(ListNode* l1, int n1, ListNode* l2, int n2, int& carry) {
        if (!l1 && !l2) { // when both list end
            return nullptr;
        }
        
        ListNode* prev = nullptr;
        int sum;
		
        if (n1 == n2) { // both list match at this index
            prev = addLists(l1->next, n1 - 1, l2->next, n2 - 1, carry);
            sum = l1->val + l2->val;
        } else if (n1 > n2) { // l1 is longer
            prev = addLists(l1->next, n1 - 1, l2, n2, carry);
            sum = l1->val;
        } else { // l2 is longer
            prev= addLists(l1, n1, l2->next, n2 - 1, carry);
            sum = l2->val;
        }
        
        sum += carry;
		auto* curr = new ListNode(sum % 10, prev);
        carry = sum / 10; // carry is passed by ref
        
        return curr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = countNodes(l1);
        int n2 = countNodes(l2);
        int carry = 0;
        
        auto* sumList = addLists(l1, n1, l2, n2, carry);
        if (carry) {
            auto* node = new ListNode(1);
            node->next = sumList;
            sumList = node;
        }
        
        return sumList;
    }
};