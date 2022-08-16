class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> after(2, vector<long>(3, 0));
        vector<vector<long>> cur(2, vector<long>(3, 0));
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int cap = 1; cap <= 2; cap++) {
                for(int buy = 0; buy < 2; buy++) {
                    if(buy) 
                        cur[buy][cap] = max(-prices[ind] + after[0][cap], after[1][cap]);
                    else 
                        cur[buy][cap] = max(prices[ind] + after[1][cap-1], after[0][cap]);
                }
            }
            after = cur;
        }
        
        return after[1][2];
    }
};