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
        ListNode* first = head, *second = head;
        bool flag = false;
        for(int i = 0; i<(n+1); i++) {
            if(!first) {
                flag = true;
                break;
            }
            if(first) {
                first = first->next;
            }
        }
        while(first) {
            first = first->next;
            second = second->next;
        }
        if(flag) {
            head = head->next;
            delete(second);
            return head;
        }
        else
            second->next = second->next->next;
        return head;
    }
};