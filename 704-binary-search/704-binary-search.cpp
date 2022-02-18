class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size()-1, l = 0;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};