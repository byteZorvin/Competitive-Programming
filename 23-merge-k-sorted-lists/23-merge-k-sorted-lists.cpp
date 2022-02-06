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
    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode*head = new ListNode();
        ListNode* result = head;
        while(first || second) {
            if(first == NULL) {
                result->next = second;
                break;
            }
            if(second == NULL) {
                result->next = first;
                break;
            }
            else if(first->val <= second->val) {
                result->next = first;
                first = first->next;
                result = result->next;
            }
            else {
                result->next = second;
                second = second->next;
                result = result->next;
            }
        }
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int i = 0, last = lists.size()-1;
        int j = last;
        while(last != 0) {
            i = 0, j = last;
            while(i<j) {
                lists[i] = merge(lists[i], lists[j]);
                i++, j--;
                if(i>=j) {
                    last = j;
                    break;
                }
            }
        }
        return lists[0];
    }
};