class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int highesAttained = prices.back(), maxProfit = 0;
        for(int i = prices.size()-1; i>=0; i--) {
            highesAttained = max(highesAttained, prices[i]);
            maxProfit = max(maxProfit, highesAttained-prices[i]);
        }
        return maxProfit;
    }
};