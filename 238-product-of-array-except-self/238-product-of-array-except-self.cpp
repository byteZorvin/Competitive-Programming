class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1, n = nums.size();
        vector<int> res(n, 1);
        for(int i = 0; i<n; i++) {
            res[i] *= prefix;
            prefix *= nums[i];
            res[n-1-i] *= suffix;
            suffix *= nums[n-1-i];
        }
        return res;
    }
};