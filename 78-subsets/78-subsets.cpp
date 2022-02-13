class Solution {
private:
    void generateSubsets(vector<vector<int>>& powerSet, vector<int>& set, vector<int>& nums, int i) {
        if(i >= nums.size()) {
            powerSet.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        generateSubsets(powerSet, set, nums, i+1);
        set.pop_back();
        generateSubsets(powerSet, set, nums, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> set;
        generateSubsets(powerSet, set, nums, 0);
        return powerSet;
    }
};