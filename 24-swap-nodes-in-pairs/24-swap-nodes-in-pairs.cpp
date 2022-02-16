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
    ListNode* swapPairs(ListNode* head, ListNode* prev = NULL) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *newHead = head->next;
        head->next = newHead->next;
        newHead->next = head;
        if(prev) prev->next = newHead;
        swapPairs(head->next, head);
        return newHead;
    }
};