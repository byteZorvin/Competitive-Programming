class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>>(2, vector<long>(3, 0)));
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int cap = 1; cap <= 2; cap++) {
                for(int buy = 0; buy < 2; buy++) {
                    if(buy) {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    }
                    else 
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap] );
                }
            }
        }
        
        return dp[0][1][2];
    }
};