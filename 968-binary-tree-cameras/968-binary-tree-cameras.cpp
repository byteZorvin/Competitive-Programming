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
    int res = 0;
    int helper(TreeNode*root) {
        if(root == NULL) 
            return 2;
        int left = helper(root->left), right = helper(root->right);
        if(left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        return (helper(root)== 0 ? 1 : 0) +  res;
    }
};