class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        long long sum = 0, ans = 0;
        int i = 0, j = 0;
        unordered_set<int> window;
        while(i<nums.size()) {
            sum += nums[i];
            while(window.find(nums[i]) != window.end()) {
                sum -= nums[j];
                window.erase(nums[j]);
                j++;
            }
            window.insert(nums[i]);
            ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};