class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                int j = i+1;
                while(j<n && nums[j] > nums[i]) j++;
                swap(nums[i], nums[j-1]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};