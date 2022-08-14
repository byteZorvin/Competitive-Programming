class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], ans = 0;
        for(int i = 1; i<prices.size(); i++) {
            ans = max(ans, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};