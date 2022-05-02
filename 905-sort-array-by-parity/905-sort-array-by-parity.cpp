class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i<j) {
            while(i<j && nums[j]%2) 
                j--;
            if(i<j && nums[i]&1) {
                swap(nums[i], nums[j]);
                j--;
            }
            i++;
        }
        return nums;
    }
};