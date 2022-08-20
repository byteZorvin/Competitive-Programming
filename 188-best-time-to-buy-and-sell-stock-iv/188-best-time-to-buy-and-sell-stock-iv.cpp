class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(cap+1, vector<int>(2, 0)));
        
        for(int ind = n-1; ind>=0; ind--) {
            for(int k = 1; k<=cap; k++) {
                for(int buy = 0; buy<2; buy++) {
                    if(buy) {
                        dp[ind][k][buy] = max(-prices[ind] + dp[ind+1][k][0] , dp[ind+1][k][1]);
                    }
                    else
                        dp[ind][k][buy] = max(prices[ind] + dp[ind+1][k-1][1], dp[ind+1][k][0]);
                }
            }
        }
        return dp[0][cap][1];
    }
};