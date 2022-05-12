class Solution {
    int findIndex(vector<int>&nums, int x) {
        int ind = -1;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == x)
                ind = i;
        }
        return ind;
    }
    
    int getProduct(vector<int>&nums) {
        int pro = 1;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i])
                pro *= nums[i];
        }
        return pro;
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = count(nums.begin(), nums.end(), 0);
        vector<int> ans(nums.size());
        if(zeroCount > 1) 
            return ans;
        
        int index = findIndex(nums, 0);
        int product = getProduct(nums);
        
        if(zeroCount == 1) {
            ans[index] = product;
        }
        else {
            for(int i = 0; i<nums.size(); i++) {
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};