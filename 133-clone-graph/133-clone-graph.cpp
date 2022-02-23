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
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        unordered_map<int, Node*> allNodes;
        set<pair<int, int>> edges;
        queue<Node*>q; 
        
        Node* head = new Node(node->val);
        allNodes[head->val] = head;
        
        q.push(node);
        
        while(!q.empty()) {
            Node* curr = q.front(); q.pop();
            for(auto &i: curr->neighbors) {
                if(allNodes.find(i->val) == allNodes.end()) {
                    Node* temp = new Node(i->val);
                    allNodes[curr->val]->neighbors.push_back(temp);
                    temp->neighbors.push_back(allNodes[curr->val]);
                    edges.insert({curr->val, temp->val});
                    edges.insert({temp->val, curr->val});
                    allNodes[i->val] = temp;
                    q.push(i);
                }
                else if(edges.find({curr->val, i->val}) == edges.end()){
                    allNodes[curr->val]->neighbors.push_back(allNodes[i->val]);
                    allNodes[i->val]->neighbors.push_back(allNodes[curr->val]);
                    edges.insert({i->val, curr->val});
                    edges.insert({curr->val, i->val});
                }
            }
        }
        return head;
    }
};