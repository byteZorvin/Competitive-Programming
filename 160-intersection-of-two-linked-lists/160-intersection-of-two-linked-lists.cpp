/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLen(ListNode*headA) {
        int len = 0;
        while(headA) {
            headA = headA->next;
            len++;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLen(headA), l2 = getLen(headB);
        if(l1>l2) {
            while(l1>l2) {
                headA = headA->next;
                l1--;
            }
        }
        else {
            while(l2>l1) {
                headB = headB->next;
                l2--;
            }
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};