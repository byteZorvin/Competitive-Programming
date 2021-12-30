class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = 0;
        for(int i = 0; i<n; i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};