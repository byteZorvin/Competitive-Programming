class Solution {
    int helper(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if(x == m) return y;
        if(grid[x][y] == 1) {
            if(y == n-1 || grid[x][y+1] == -1)
                return -1;
            else return helper(grid, x+1, y+1);
        }
        else {
            if(y == 0 || grid[x][y-1] == 1)
                return -1;
            else return helper(grid, x+1, y-1);
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i = 0; i<grid[0].size(); i++) {
            ans[i] = helper(grid, 0, i);
        }
        return ans;
    }
};