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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = new ListNode();
        ListNode* tail = head;
        int carry = 0;
        while(l1 || l2 || carry) {
            int val = carry;
            if(l2)  {
                val += l2->val;
                l2 = l2->next;
            } 
            if(l1) {
                val += l1->val;
                l1 = l1->next;
            }
            
            tail->next = new ListNode(val%10);
            carry = val/10;
            
            tail = tail->next;
        }
        return head->next;
    }
};