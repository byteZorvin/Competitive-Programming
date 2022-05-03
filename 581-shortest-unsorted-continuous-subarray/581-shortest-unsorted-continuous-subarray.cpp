class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        bool flag = false;
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i-1]) 
                flag = true;
            if(flag) mini = min(mini, nums[i]);
        }
        flag = false;
        for(int i = n-2; i>=0; i--) {
            if(nums[i]>nums[i+1]) 
                flag = true;
            if(flag) maxi = max(maxi, nums[i]);
        }
        int leftB = n, rightB = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] > mini) {
                leftB = i; 
                break;
            }
        }
        for(int i = n-1; i>=0; i--) {
            if(maxi>nums[i]) {
                rightB = i;
                break;
            }
        }
        return max(0, rightB - leftB + 1);
    }
};