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
private:
    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = NULL;
        ListNode* fast = head;
        while(fast && fast->next) {
            midPrev = (midPrev == NULL) ? head : midPrev->next;
            fast = fast->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
private:
    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(first && second) {
            if(first->val < second->val) {
                tail->next = first;
                first = first->next;
            }
            else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        if(first) 
            tail->next = first;
        else 
            tail->next = second;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};