class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n+1;
        vector<int> prefix(n);
                
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(int i = 0; i<n; i++) {
            int to_find = target;
            if(i>0) to_find += prefix[i-1];
            if(to_find>prefix[n-1])continue;
            int index = lower_bound(prefix.begin(), prefix.end(), to_find) - prefix.begin();
            ans = min(ans, index-i+1);
        } 
        return ans == n+1 ? 0 : ans;
    }
};