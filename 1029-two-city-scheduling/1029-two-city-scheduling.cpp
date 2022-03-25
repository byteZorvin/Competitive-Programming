class Solution {
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[0]-a[1] > b[0] - b[1];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int ans = 0, a = 0, b = 0, n = costs.size();
        for(int i = 0; i<n; i++) {
            if(i<n/2) ans += costs[i][1];
            else ans += costs[i][0];
        }
        return ans;
    }
};