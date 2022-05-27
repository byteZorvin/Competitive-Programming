class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        obstacleGrid[0][0] = 1;
        
        for(int i = 1; i<n; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0
                                  && obstacleGrid[i-1][0] == 1) ? 1 : 0;
        }
        for(int j = 1; j<m; j++) {
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && 
                                  obstacleGrid[0][j-1] ==1) ? 1 : 0;
        }
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                else 
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};