class Solution {
private: 
    bool checkValid(vector<vector<int>>&grid, int x, int y) {
        return (x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 1);
    }
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int x, int y) {
        vis[x][y] = 1;     
        vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int size = 1;
        for(int i = 0; i<4; i++) {
            int a = x + dir[i].first, b = y + dir[i].second;
            if(checkValid(grid, a, b) && !vis[a][b]) {
                size += dfs(grid, vis, a, b);
            }
        }
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int maxArea = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!vis[i][j] && grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(grid, vis, i, j));
            }
        }
        return maxArea;
    }
};