class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, count = 1;
        for(int i = 2; i<n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) 
                count++;
            else {
                int sbarrcnt = count*(count+1)/2 - count;
                ans += sbarrcnt > 0 ? sbarrcnt : 0;
                count = 1;
            }
        }
        int sbarrcnt = count*(count+1)/2 - count;
        ans += sbarrcnt > 0 ? sbarrcnt : 0;
        return ans;
    }
};