class Solution {
    vector<vector<int>> ans;
private:
    void helper(int n, int k, int start, vector<int> &combination) {
        if(k == 0) {
            ans.push_back(combination);
            return;
        }
        for(int i = start; i<=n; i++) {
            combination.push_back(i);
            helper(n, k-1, i+1, combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        helper(n, k, 1, vector<int>()={});
        return ans;
    }
};