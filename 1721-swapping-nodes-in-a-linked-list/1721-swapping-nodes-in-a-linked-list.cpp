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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = NULL, *n2 = NULL;
        ListNode* curr = head; 
        while(curr != NULL) {
            if(n2) n2 = n2->next;
            if(--k == 0) {
                n1 = curr;
                n2 = head;
            }
            curr = curr->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};