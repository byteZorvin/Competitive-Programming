class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size()-1;
        while(j<=k) {
            if(nums[j] == 0) {
                swap(nums[i++], nums[j]);
                j++;
            }
            else if(nums[j] == 2) {
                swap(nums[k--], nums[j]);
            }
            else
                j++;
        }
    }
};