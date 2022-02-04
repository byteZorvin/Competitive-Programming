class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int longest = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) count--;
            else count++;
            auto it = mp.find(count);
            if(it != mp.end()) {
                longest = max(longest, i - it->second);
            }
            else mp[count] = i;
        }
        
        return longest;
    }
};