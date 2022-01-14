class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), totalOnes = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 1) totalOnes++;
        }
        if(totalOnes == 0 || totalOnes == n) {
            return 0;
        }
        int count = 0, start = 0, ans = n;
        for(int i = 0; i<totalOnes; i++) {
            if(nums[i] == 0) count++;
        }
        ans = min(ans, count);
        start++;
        for(int i = start; i<n; i++) {
            int j = (i+totalOnes-1)%n;
            if(nums[i-1] == 0 && nums[j] == 1)
                count--;
            else if(nums[i-1] == 1 and nums[j] == 0) 
                count++;
            ans = min(ans, count);
        }
        return ans;
    }
};