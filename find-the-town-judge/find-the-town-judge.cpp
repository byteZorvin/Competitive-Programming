class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<bool, int>> candidature(n);
        for(int i = 0; i<n; i++) {
            candidature[i].first = true;
        }
        
        for(auto edge : trust) {
            candidature[edge[0]-1].first = false;
            candidature[edge[1]-1].second++;
        }
        
        for(int i = 0; i<n; i++) {
            if(candidature[i].first and candidature[i].second == n-1) 
                return i+1;
        }
        return -1;
    }
};