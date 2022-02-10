class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]++;
        
        int sum = 0, n = nums.size(), ans = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            ans += m[sum-k];
            m[sum]++;
        }
        
        return ans;
    }
};