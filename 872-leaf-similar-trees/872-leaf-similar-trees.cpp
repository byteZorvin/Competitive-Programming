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
    void preorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        preorder(root->left, v);
        preorder(root->right, v);
        if(!root->left && !root->right) v.push_back(root->val);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        preorder(root1, first);
        preorder(root2, second);
        return first == second;
    }
};