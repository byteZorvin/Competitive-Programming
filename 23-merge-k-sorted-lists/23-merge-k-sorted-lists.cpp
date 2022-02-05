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
// private:
//     ListNode* tail = NULL, *head = NULL;
private:
    // void mergeList(ListNode*first, ListNode* second) {
    //     while(first || second) {
    //         if(first == NULL) {
    //             tail->next = second;
    //             tail = tail->next;
    //             second = second->next;
    //         }
    //         else if(second == NULL) {
    //             tail->next = first;
    //             tail = tail->next;
    //             first = first->next;
    //         }
    //         else if(first->val <= second->val) {
    //             tail->next = first;
    //             tail = tail->next;
    //             first = first->next;
    //         }
    //         else {
    //             tail->next = second;
    //             tail->next = tail;
    //             second->next = second;
    //         }
    //         // ListNode* &workingNode = !first? second : !second ? first : first->val <= second->val ? first:second;
    //         // tail->next = exchange(workingNode, workingNode->next);
    //         // tail = tail->next;
    //     }
    // }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int n = lists.size();
        // ListNode dummy; dummy.next = NULL;
        // tail = head = &dummy;
        // for(int i = 1; i<n; i+=2) {
        //     mergeList(lists[0], lists[i]);
        //     lists[0] = head;
        // }
        // if(n&1) tail->next = lists[n-1];
        // return head->next;
        
        vector<int> values;
        for(int i = 0; i<lists.size(); i++) {
            ListNode* curr = lists[i];
            while(curr) {
                values.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(values.begin(), values.end());
        
        ListNode dummy; 
        ListNode * head, *tail;
        
        head = tail = &dummy;
        for(auto &i: values) {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
        return head->next;
    }
};