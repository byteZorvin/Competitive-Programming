class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto i: nums)
            mp[i]++;
        
        for(auto &i : mp) {
            if(k != 0) {
                ans += (mp.find(i.first+k) != mp.end() && mp.find(i.first+k)->second != -1);
                ans += (mp.find(i.first-k) != mp.end() && mp.find(i.first-k)->second != -1);
            }
            else {
                ans += i.second>1;
            }
            mp[i.first] = -1;
        }
        
        return ans;
    }
};