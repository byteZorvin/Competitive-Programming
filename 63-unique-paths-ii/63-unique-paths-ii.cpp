class Solution {
    bool valid(vector<vector<int>>&obstacleGrid, int i, int j) {
        return i>=0 && j>=0 && i<obstacleGrid.size() && j<obstacleGrid[0].size() 
            && obstacleGrid[i][j] == 0;
    }
    
    int uniquePaths(vector<vector<int>>&obstacleGrid, int i, int j, vector<vector<int>> &dp) {
        if(!valid(obstacleGrid, i, j)) return 0;
        if(i == 0 && j==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = uniquePaths(obstacleGrid, i-1, j, dp)+uniquePaths(obstacleGrid, i, j-1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return uniquePaths(obstacleGrid, n-1, m-1, dp);
    }
};