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
    int ans = 0;
    map<int, int> m;
private:
    void dfs(TreeNode* node, long long x, int level) {
        if(node == NULL) return;  
        if(m.find(level) == m.end()) {
            m[level] = x;
            x = 0;
        }
        else 
            x = x - m[level];
        ans = max((long long)ans, x + 1);
        dfs(node->left, (long long)2*x + 1, level+1);
        dfs(node->right, (long long)2*x + 2, level+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0LL, 0);
        return ans;
    }
};