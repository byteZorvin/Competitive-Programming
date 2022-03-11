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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k %= len;
        int x = len-k-1;
        while(x--) {
             head = head->next;
        }
        ListNode*nHead = head->next;
        head->next = NULL;
        return nHead;
    }
};