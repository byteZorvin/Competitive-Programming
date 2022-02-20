class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int high = 0, ans = 0, n = prices.size();
        for(int i = n-1; i>=0; i--) {
            ans = max(ans, high-prices[i]);
            high = max(high, prices[i]);
        }
        return ans;
    }
};