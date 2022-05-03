class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int first = n, last = -1;
        for(int i = 0; i<n; i++) {
            if(nums[i] != temp[i]) {
                first = min(first, i);
                last = max(last, i);
            }
        }
        if(first ==n && last == -1) return 0;
        else return last - first + 1;
    }
};