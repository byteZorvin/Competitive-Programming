class Solution {
    vector<vector<int>> ans;
private:
    void helper(int n, int k, int start, vector<int> &combination) {
        if(k == 0) ans.push_back(combination);
        for(int i = start; i<=n; i++) {
            combination.push_back(i);
            helper(n, k-1, i+1, combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        helper(n, k, 1, combination);
        return ans;
    }
};