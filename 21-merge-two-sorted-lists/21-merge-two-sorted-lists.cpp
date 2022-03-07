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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(list1 && list2) {
            ListNode*&workingNode = list1->val < list2->val ? list1 : list2;
            tail->next = workingNode;
            workingNode = workingNode->next;
            tail = tail->next;
        }
        if(list1) tail->next = list1;
        else tail->next = list2;
        return head->next;
    }
};