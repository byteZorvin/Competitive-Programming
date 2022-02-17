class Solution {
    vector<vector<int>> ans;
private:
    void backtrack(vector<int>&candidates, vector<int>&subset, int sum, int l) {
        if(sum == 0) {
            ans.push_back(subset);
            return;
        }
        int r = candidates.size();
        for(int i = l; i<r; i++) {
            if(candidates[i]<=sum) {
                subset.push_back(candidates[i]);
                backtrack(candidates, subset, sum-candidates[i], i);
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans = vector<vector<int>>();
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, subset, target, 0);
        return ans;
    }
};