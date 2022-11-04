class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, int steps, int totalSteps) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1) return 0;
        if(grid[i][j] == 2) return totalSteps == steps;
        grid[i][j] = -1;
        
        int paths = dfs(grid, i+1, j, steps+1, totalSteps) + dfs(grid, i, j+1, steps+1, totalSteps)
                    + dfs(grid, i-1, j, steps+1, totalSteps) + dfs(grid, i, j-1, steps+1, totalSteps);
        
        grid[i][j] = 0;
        
        return paths;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        int i1 = 0, j1 = 0, totalSteps = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) i1 = i, j1 = j;
                if(grid[i][j] != -1) totalSteps++;
            }
        }
        return dfs(grid, i1, j1, 1, totalSteps);
    }
};