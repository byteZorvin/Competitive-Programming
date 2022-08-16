class Solution {
    long long recursiveProfit(int ind, int buy, vector<int>&prices, vector<vector<long long>>&dp) {
        if(ind == prices.size()) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) {
            profit = max(-prices[ind] + recursiveProfit(ind+1, 0, prices, dp), recursiveProfit(ind+1, 1, prices, dp));
        }
        else {
            profit = max(prices[ind] + recursiveProfit(ind+1, 1, prices, dp), recursiveProfit(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>>dp(n, vector<long long>(2, -1));
        return recursiveProfit(0, 1, prices, dp);
    }
};