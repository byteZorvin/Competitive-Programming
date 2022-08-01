class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while(true) {
            int candidate = nums[rand()%nums.size()];
            int count = nums.size()/2;
            for(auto n: nums) {
                if(n == candidate) count--;
            }
            if(count < 0) return candidate;
        }
    }
};