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
    void solve(TreeNode* root, int &sum){
        if(root==NULL){
            return;
        }
        solve(root->right, sum);
        root->val=sum+root->val;
        sum=root->val;
        solve(root->left, sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int num=0;
        solve(root, num);
        return root;
    }
};