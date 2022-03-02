class Solution {
private:
    vector<vector<int>> ans;
   void getPermutation(vector<int>&nums, int i) {
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int j = i; j<nums.size(); j++) {
            swap(nums[j], nums[i]);
            getPermutation(nums, i+1);
            swap(nums[j], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        getPermutation(nums, 0);
        return ans;
    }
};