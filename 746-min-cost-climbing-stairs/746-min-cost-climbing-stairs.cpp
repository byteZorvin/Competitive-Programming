class Solution {
private:
    int minCost(vector<int>&cost, int i, vector<int>& dp) {
        if(i==0 || i==1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = min(cost[i-1]+minCost(cost, i-1, dp), cost[i-2]+minCost(cost, i-2, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return minCost(cost, n, dp);
    }
};