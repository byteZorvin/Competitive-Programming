class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, ans = h + 1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else {
                ans = mid;
                h = mid-1;
            }
        }
        return ans;
    }
};