class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(auto &str: strs) {
            int zeroCount = count(str.begin(), str.end(), '0');
            int oneCount = str.size() - zeroCount;
            
            for(int i = m; i>=zeroCount; i--) {
                for(int j = n; j>=oneCount; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeroCount][j-oneCount]);
                }
            }
        }
        
        return dp[m][n];
    }
};