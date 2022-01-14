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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        stack<int> s;
        while(slow) {
            s.push(slow->val);
            slow = slow->next;
        }
        int ans = INT_MIN;
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            ans = max(ans, fast->val+top);
            fast = fast->next;
        }
        return ans;
    }
};