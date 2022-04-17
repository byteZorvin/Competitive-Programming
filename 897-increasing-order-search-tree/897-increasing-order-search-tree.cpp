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
    TreeNode* inorder(TreeNode *cur, TreeNode *ans) {
        if (cur == nullptr) return ans;
        TreeNode *now = inorder(cur->left, ans);
        now->right = new TreeNode(cur->val);
        return inorder(cur->right, now->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *cur = new TreeNode();
        inorder(root, cur);
        return cur->right;
    }
};