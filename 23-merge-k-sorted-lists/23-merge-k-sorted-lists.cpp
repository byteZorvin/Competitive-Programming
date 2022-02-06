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
class comp {
public:
    bool operator() (const ListNode* left, const ListNode* right) {
        return left->val > right->val;
    }
};


class Solution {    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode dummy;
        ListNode* head = &dummy, *tail = &dummy;
        for(auto &list: lists) {
            if(list) pq.push(list);
        }
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if(node->next) pq.push(node->next);
            tail->next = node;
            tail = tail->next;
        }
        return head->next;
    }
};