class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_reach = 0, myPos = 0;
        
        while(can_reach < nums.size()-1) {
            int range = can_reach;
            for(int i = myPos; i<=can_reach; i++) {
                if(i+nums[i] > range) {
                    range = i + nums[i]; 
                    myPos = i;
                }
            }
            if(range == can_reach) return false;
            can_reach = range;
        }
        return can_reach >= nums.size() - 1;
    }
};