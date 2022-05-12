class Solution {
    void generate(vector<vector<int>>&res, vector<int> &perm, int n, unordered_map<int, int> &count) {
        if(perm.size() == n) {
            res.push_back(perm);
            return;
        }
        for( auto &e: count ) {
            if(e.second == 0) continue;
            perm.push_back(e.first);
            e.second--;
            generate(res, perm, n, count);
            perm.pop_back();
            e.second++;
        }
    }
    unordered_map<int, int> getHash(vector<int>&nums) {
        unordered_map<int, int> mp;
        for(auto &i: nums) 
            mp[i]++;
        return mp;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        unordered_map<int, int> count = getHash(nums);
        generate(res, perm, nums.size(), count);
        return res;
    }
};