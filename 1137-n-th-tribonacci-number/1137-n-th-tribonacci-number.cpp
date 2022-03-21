class Solution {
    int helper(int n, int *dp) {
        if(dp[n] != -1) return dp[n];
        if(n == 1 || n == 2) return dp[n] = 1;
        else return dp[n] = helper(n-1, dp) + helper(n-2, dp) + helper(n-3, dp);
    }
public:
    int tribonacci(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        return helper(n, dp);
    }
};