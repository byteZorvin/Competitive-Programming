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
        ListNode* tail = head;
        while(first || second) {
            ListNode* &workingNode = !first? second : !second ? first : first->val <= second->val ? first:second;
            tail->next = exchange(workingNode, workingNode->next);
            tail = tail->next;
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