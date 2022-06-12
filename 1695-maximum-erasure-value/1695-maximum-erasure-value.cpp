class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> window;
         for(int j = 0, i = 0, sum = 0; i<nums.size(); i++) {
            sum += nums[i];
            while(window.find(nums[i]) != window.end()) {
                sum -= nums[j];
                window.erase(nums[j]);
                j++;
            }
            window.insert(nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};