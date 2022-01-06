class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> times;
        for(auto data : trips) {
            times.push_back({data[1], data[0]});
            times.push_back({data[2], -data[0]});
        }
        sort(times.begin(), times.end());
        
        int passenger_count = 0;
        for(auto time : times) {
            passenger_count += time.second;
            if(passenger_count>capacity) return false;
        }
        return true;
    }
};