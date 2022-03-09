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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* tail = dummy;
        while(tail->next) {
            ListNode*next = tail->next->next;
            while(next && next->val == tail->next->val) {
                next = next->next;
            }
            if(next != tail->next->next) 
                tail->next = next;
            else
                tail = tail->next;
        }
        
        return dummy->next;
    }
};