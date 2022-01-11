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
    void dfs(TreeNode* root, int &sum, int currsum = 0) {
        if(root == NULL) return;
        else currsum = currsum*2 + root->val;
        if(!root->left and !root->right) sum += currsum;
        dfs(root->left, sum, currsum);
        dfs(root->right, sum, currsum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};