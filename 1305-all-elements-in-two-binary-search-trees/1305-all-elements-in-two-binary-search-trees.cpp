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
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        stack<TreeNode*> st1, st2;
        TreeNode* first = root1, *second = root2;

        while(!st1.empty() or !st2.empty() or first or second) {
            while(first != NULL) {
                st1.push(first);
                first = first->left;
            }
            while(second != NULL) {
                st2.push(second);
                second = second->left;
            }
            
            if(!st1.empty() && !st2.empty()) {
                if(st1.top()->val < st2.top()->val) {
                    first = st1.top();
                    st1.pop();
                    ans.push_back(first->val);
                    first = first->right;
                } 
                else{
                    second = st2.top();
                    st2.pop();
                    ans.push_back(second->val);
                    second = second->right;
                }
            }   
            else if(!st1.empty()) {
                first = st1.top();
                st1.pop();
                ans.push_back(first->val), first = first->right;
            }
            else {
                second = st2.top();
                st2.pop();
                ans.push_back(second->val);
                second = second->right;
            }
        }
        
        return ans;
    }
};