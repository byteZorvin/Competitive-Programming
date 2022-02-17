class Solution {
    vector<vector<int>> ans;
private:
    void helper(vector<int>&candidates, vector<int>&current, int sum, int i) {
        if(sum<0 || i>=candidates.size()) return;
        if(sum == 0) {
            ans.push_back(current);
            return;
        }
        helper(candidates, current, sum, i+1);
        current.push_back(candidates[i]);
        helper(candidates, current, sum-candidates[i], i);
        current.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        ans = vector<vector<int>>();
        helper(candidates, current, target, 0);
        return ans;
    }
};