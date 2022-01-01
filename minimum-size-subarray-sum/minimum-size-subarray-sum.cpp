class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int curr_sum = 0, ans = n+1;
        while(j<n) {
            curr_sum += nums[j];
            j++;
            while(curr_sum>=target && i<j) {
                ans = min(ans, j-i);
                // cout << i << " " << j << '\n';
                curr_sum -= nums[i];
                i++;
            }
        }
        if(ans == n+1) ans = 0;
        return ans;
    }
};