class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, curr = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            curr = max(nums[i], curr+nums[i]);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};