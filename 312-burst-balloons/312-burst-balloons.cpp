class Solution {
private:
    int f(int left, int right, vector<int>&nums, vector<vector<int>> &dp) {
        if(left>right) return 0;
        if(dp[left][right] != -1) return dp[left][right];                                                               
        int maxi = INT_MIN;
        for(int l = left; l<=right; l++) {
            int cost = nums[l]*nums[left-1]*nums[right+1] + f(left, l-1, nums, dp) + f(l+1, right, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[left][right] = maxi;                                                                   
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(1, nums.size()-2, nums, dp);
    }
};