class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucket sort
        unordered_map<int, int> count;
        for(auto &i: nums) 
            count[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &ele: count) {
            bucket[ele.second].push_back(ele.first);
        }
        vector<int> res;
        for(int i = bucket.size()-1; i>=0; i--) {
            for(int j = 0; j<bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};