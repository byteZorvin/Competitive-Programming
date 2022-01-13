class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int ones = 0;
        for(int j = 0; j<2; j++) {
            for(int i = 0; i<n; i++){
                arr.push_back(nums[i]);
                if(nums[i]) ones++;
            }
        }
        ones /= 2;
        if(ones == 0) return 0;
        int zeros = 0;
        int start = 0, end = -1, ans = 2*n;
        while(end<2*n) {
            if(end-start+1<ones) {
                end++;
                if(end==2*n) return ans;
                if(arr[end]==0) zeros++;
            }
            if(end-start+1==ones) {
                ans = min(ans, zeros);
                if(arr[start]==0) zeros--;
                start++;
            }
        }
        return ans;
    }
};