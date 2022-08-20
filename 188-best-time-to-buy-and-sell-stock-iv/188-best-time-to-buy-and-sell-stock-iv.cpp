class Solution {
    int f(int ind, int tranNo, int k, vector<int>&prices, vector<vector<int>> &dp) {
        if (ind == prices.size() || tranNo == 2*k) return 0;
        
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        if(tranNo%2) {
            //sell
            return dp[ind][tranNo] = max(prices[ind] + f(ind+1, tranNo+1, k, prices, dp), f(ind+1, tranNo, k, prices, dp));
        }
        return dp[ind][tranNo] = max(-prices[ind] + f(ind+1, tranNo+1, k, prices, dp), f(ind+1, tranNo, k, prices, dp));
    }
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*cap, -1));
        return f(0, 0, cap, prices, dp);
    }
};