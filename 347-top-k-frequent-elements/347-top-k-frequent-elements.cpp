class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Getting freq map
        unordered_map<int, int> cnt;
        for(auto &i: nums) {
            cnt[i]++;
        }
        
        // Building min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &e: cnt) {
            pq.push({e.second, e.first});
            if(pq.size() > k) 
                pq.pop();
        }
        
        // Res array
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};