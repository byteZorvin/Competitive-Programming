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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*first = head, *second = head;
        while(n--) {
            second = second->next;
        }
        if(second == NULL) {
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        second = second->next;
        
        while(second) {
            first = first->next;
            second = second->next;
        }
        
        ListNode* temp = first->next;
        first->next = first->next->next;
        delete(temp);
        return head;
    }
};