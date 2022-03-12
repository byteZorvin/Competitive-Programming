/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node*dummy = new Node(0);
        Node* curr = head, *tail = dummy;
        while(curr) {
            if(mp.find(curr) == mp.end()) {
                mp[curr] = new Node(curr->val);
            }
            if(curr->random && mp.find(curr->random) == mp.end()) {
                mp[curr->random] = new Node(curr->random->val);
            }
            tail->next = mp[curr];
            tail->next->random = mp[curr->random];
            tail = tail->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};