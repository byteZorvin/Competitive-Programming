/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {   
public:
    Node* connect(Node* root) {
        Node* curr = root, *head = nullptr, *tail = nullptr;
        
        while(curr) {
            if(curr->left) {
                if(tail) tail = tail->next = curr->left;
                else 
                    head = tail = curr->left;
            }
            if(curr->right) {
                if(tail) tail = tail->next = curr->right;
                else 
                    head = tail = curr->right;
            }
            curr = curr->next;
            if(curr == NULL) {
                curr = head;
                head = tail = NULL;
            }
        }
        return root;
    }
};