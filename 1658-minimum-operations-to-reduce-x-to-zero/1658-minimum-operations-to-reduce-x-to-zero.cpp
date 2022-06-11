class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x, current = 0;
        for(auto &it: nums) {
            target += it;
        }
        int i = 0, j = 0, res = -1;
        while(j<nums.size() && target>=0) {
            current += nums[j++];
            while(current > target) {
                current -= nums[i++];
            }
            if(current == target) 
                res = max(res, j-i);
        }
        if(res != -1)
            res = nums.size() - res;
        return res;
    }
};