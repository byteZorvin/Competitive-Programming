class Solution {
    void generate(vector<vector<int>>&res, vector<int> nums, int i, int n) {
        if(i == n - 1) {
            res.push_back(nums);
            return;
        }
        for(int k = i; k<n; k++ ) {
            if(k > i && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            generate(res, nums, i+1, n);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        generate(res, nums, 0, nums.size());
        return res;
    }
};