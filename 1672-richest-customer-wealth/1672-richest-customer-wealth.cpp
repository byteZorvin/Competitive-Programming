class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts[0].size(), n = accounts.size(), highest = 0;
        for(int i = 0; i<n; i++) {
            int money = 0;
            for(int j = 0; j<m; j++) {
                money += accounts[i][j];
            }
            highest = max(highest, money);
        }
        return highest;
    }
};