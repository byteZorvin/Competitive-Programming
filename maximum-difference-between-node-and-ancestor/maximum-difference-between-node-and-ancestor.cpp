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
    int ans = 0;
private:
    void getextreme(TreeNode* root, int &minn, int &maxx) {
        if(!root) return;
        maxx = max(maxx, root->val);
        minn = min(minn, root->val);
        getextreme(root->left, minn, maxx);
        getextreme(root->right, minn, maxx);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int minn = root->val, maxx = root->val;
        getextreme(root, minn, maxx); 
        ans = max(ans, abs(root->val - minn));
        ans = max(ans, abs(maxx - root->val));
        
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);

        return ans;
    }
};