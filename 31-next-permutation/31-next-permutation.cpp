class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1;
        while(i>0) {
            if(nums[i-1] >= nums[i]) {
                i--;
            }
            else
                break;
        }
        if(i >0) {
            for(int j = n-1; j>=i; j--) {
                if(nums[j]>nums[i-1]) {
                    swap(nums[j], nums[i-1]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i, nums.end());
    }
};