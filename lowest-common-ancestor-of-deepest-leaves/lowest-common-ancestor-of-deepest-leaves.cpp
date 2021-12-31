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
    TreeNode* lca = nullptr;
    int max_depth = 0;
    int postorder(TreeNode* root, int curr_depth = 1) {
        if(!root) return 0;
        max_depth = max(max_depth, curr_depth);
        int left = postorder(root->left, curr_depth + 1);
        int right = postorder(root->right, curr_depth + 1);
        if(left == right && left+curr_depth == max_depth) lca = root;
        return 1 + max(left, right);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        postorder(root);    
        return lca;
    }
};