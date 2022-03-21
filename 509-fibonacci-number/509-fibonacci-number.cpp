class Solution {
    int helper(int n, int *dp) {
        if(dp[n] != -1) {
            return dp[n];
        }
        if(n<=1) return dp[n] = n;
        else return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
public:
    int fib(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return helper(n, dp);
    }
};