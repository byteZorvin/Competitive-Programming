class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for(auto &i: barcodes) 
            mp[i]++;
    
        priority_queue<pair<int, int>> pq;
        for(auto &i: mp) 
            pq.push({i.second, i.first});
        
        vector<int> ans;
        while(!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            ans.push_back(a.second);
            if(!pq.empty()) {
                auto b = pq.top();
                pq.pop();  
                ans.push_back(b.second);
                if(b.first>1) pq.push({--b.first, b.second});
            }
            if(a.first>1) pq.push({--a.first, a.second});
        }
        return ans;
    }
};