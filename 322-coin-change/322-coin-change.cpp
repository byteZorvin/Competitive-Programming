class Solution {
    int func(vector<int>&coins, int sum, int i, vector<vector<int>> &dp) {
        if(i<0 || sum<0) return 1e7;
        if(sum == 0) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        return dp[i][sum] = min(1+func(coins, sum-coins[i], i, dp), func(coins, sum, i-1, dp));
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int mini = func(coins, amount, coins.size()-1, dp);
        return mini == 1e7 ? -1 : mini;
    }
};