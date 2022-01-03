class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> candidature(n+1, 0);
        for(auto &t: trust)
            candidature[t[0]]--, candidature[t[1]]++;
        
        for(int i = 1; i<=n; i++) {
            if(candidature[i] == n-1) 
                return i;
        }
        return -1;
    }
};