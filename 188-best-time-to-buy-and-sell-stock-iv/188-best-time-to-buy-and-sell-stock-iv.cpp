class Solution {
    int f(vector<int>&prices, int k, int ind, int buy, vector<vector<vector<int>>> &dp) {
        if(k == 0 || ind == prices.size()) return 0;
        if(dp[ind][k][buy] != -1) return dp[ind][k][buy];
        if(buy) {
            return dp[ind][k][buy] = max(-prices[ind] + f(prices, k, ind+1, 0, dp), f(prices, k, ind+1, 1, dp));
        }
        return dp[ind][k][buy] = max(prices[ind] + f(prices, k-1, ind+1, 1, dp), f(prices, k, ind+1, 0, dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return f(prices, k, 0, 1, dp);
    }
};