class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int dpPrev = 0, dp = 0;
        for(int i = 2; i<n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) 
                dp = dpPrev + 1;
            ans += dp;
            dpPrev = dp;
            dp = 0;
        }
        return ans;
    }
};