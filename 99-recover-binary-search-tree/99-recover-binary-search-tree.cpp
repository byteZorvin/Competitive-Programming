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
    TreeNode*first = NULL, *second = NULL, *prev = NULL;
    void solve(TreeNode*root) {
        if(root == NULL) return;
        solve(root->left);
        if(prev != NULL && root->val < prev->val) {
            if(first == NULL)
                first = prev;
            second = root;
        }
        prev = root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val, second->val);
    }
};