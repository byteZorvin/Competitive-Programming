class Solution {
    public boolean winnerSquareGame(int n) {
        boolean []dp = new boolean[n+1];
        for(int i=1; i<=n; i++)
            for(int j = (int)Math.sqrt(i); !dp[i] && j >= 1; j--)
                dp[i] = !dp[i -j*j];
        return dp[n];
    }
}