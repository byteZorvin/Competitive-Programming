class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for(auto &i: barcodes) 
            mp[i]++;
    
        priority_queue<pair<int, int>> pq;
        for(auto &i: mp) 
            pq.push({i.second, i.first});
        
        int i = 0, n = barcodes.size();
        vector<int> ans(n);
        while(!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            while(a.first--) {
                ans[i] = a.second;
                i += 2;
                if(i>=n) i = 1;
            } 
        }
        return ans;
    }
};