class Solution {
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) 
            return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>lis;
        for(int i = 0; i<n; i++) {
            int ind = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if (ind == lis.size()) lis.push_back(envelopes[i][1]);
            else lis[ind] = envelopes[i][1];
        }
        return lis.size();
    }
};