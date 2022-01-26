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
class Solution {
private:
    void pushLeft(stack<TreeNode*> &s, TreeNode *n) {
        while(n != NULL) 
            s.push(exchange(n, n->left));
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;  
        stack<TreeNode*> st1, st2;
        pushLeft(st1, root1);
        pushLeft(st2, root2);
        while(!st1.empty() || !st2.empty()) {
            stack<TreeNode*> &s = st1.empty() ? st2 : st2.empty() ? st1 : st1.top()->val <= st2.top()->val ? st1 : st2;
            auto n = s.top(); s.pop();
            ans.push_back(n->val);
            pushLeft(s, n->right); 
        }
        return ans;
    }
};