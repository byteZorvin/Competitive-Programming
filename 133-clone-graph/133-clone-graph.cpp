/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        copies[node] = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node* curr = q.front(); q.pop();
            
            for(auto neigh: curr->neighbors) {
                if(copies.find(neigh) == copies.end()) {
                    copies[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                copies[curr]->neighbors.push_back(copies[neigh]);
            }
        }
        return copies[node];
    }
};