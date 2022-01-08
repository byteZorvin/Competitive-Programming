class Solution {
    int dp[100][100][100];
private:
    int helper(int i, int j, int k, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(i>=m || j<0 || j>=n || k<0 || k>=n) {
            return 0;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int maxRes = max({
            helper(i+1, j, k, grid),
            helper(i+1, j, k+1, grid),
            helper(i+1, j, k-1, grid),
            
            helper(i+1, j+1, k, grid),
            helper(i+1, j+1, k+1, grid),
            helper(i+1, j+1, k-1, grid),
            
            helper(i+1, j-1, k, grid),
            helper(i+1, j-1, k+1, grid),
            helper(i+1, j-1, k-1, grid)
        });
            
        if(j == k) {
            return dp[i][j][k] = grid[i][j] + maxRes;
        }
        
        return dp[i][j][k] = grid[i][j] + grid[i][k] + maxRes;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return helper(0, 0, n-1, grid);
    }
};