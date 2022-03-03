/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class bstIterator {
private:
    stack<TreeNode*>s;
    bool forward;
    TreeNode* curr;
public:
    bstIterator(TreeNode* root, bool forward) : curr(root), forward(forward){};
    
    int next() {
        while(!s.empty() || curr) {
            if(curr) {
                s.push(curr);
                curr = forward ? curr->left : curr->right;
            }
            else {
                TreeNode* temp = s.top();
                s.pop();
                curr = forward ? temp->right : temp->left;
                return temp->val;
            }
        }
        return -1;
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        bstIterator l(root, true);
        bstIterator r(root, false);
        int i = l.next(), j = r.next();
        
        while(i<j) {
            int sum = i+j;
            if(sum == k) return true;
            else if(sum < k)
                i = l.next();
            else 
                j = r.next();
        }
        return false;
    }
};