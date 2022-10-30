class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> both_times;
        int n = plantTime.size();
        for(int i = 0; i<n; i++) {
            both_times.push_back({growTime[i], plantTime[i]});
        }
        sort(both_times.rbegin(), both_times.rend());
        int maxTime = 0, currTime = 0;
        for(int i = 0; i<n; i++) {
            currTime += both_times[i].second;
            maxTime = max(maxTime, currTime + both_times[i].first);
        }
        return maxTime;
    }
};