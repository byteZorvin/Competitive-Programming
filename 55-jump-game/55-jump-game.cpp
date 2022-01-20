class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int can_reach = 0, n = nums.size();
        // for(int i = 0; i<= can_reach; ++i) {
        //     if(i == n-1) return true;
        //     can_reach = max(can_reach, i+nums[i]);
        // }
        // return false;
        
        
        int n = nums.size();
        int jumps = 0, can_reach = 0;
        pair<int, int> interval{0, 0};
        
        while(true) {
            jumps++;
            for(int i = interval.first; i<=interval.second; i++) {
                can_reach = max(can_reach, i+nums[i]);
            }
            if(can_reach >= n-1) {
                cout << jumps << endl;
                return true;
            }
            interval = {interval.second+1, can_reach};
            
            if(interval.first > interval.second) {
                return false;
            }
        }
    
        assert(false);
    }
};