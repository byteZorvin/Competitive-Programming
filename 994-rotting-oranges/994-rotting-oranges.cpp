class Solution {
private:
    bool checkValid(vector<vector<int>> &grid, int i, int j) {
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j] == 1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int totalOranges = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                totalOranges += (grid[i][j] != 0);
            }
        }

        int minutes = 0, count = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i<sz; i++) {
                auto rotten = q.front();
                q.pop();
                count++;
                
                int x = rotten.first, y = rotten.second;
                vector<int> v{1, -1};
                for(auto &c: v) {
                    if(checkValid(grid, x, y+c)) {
                        grid[x][y+c] = 2;
                        q.push({x, y+c});
                    }
                    if(checkValid(grid, x+c, y)) {
                        grid[x+c][y] = 2;
                        q.push({x+c, y});
                    }
                } 
            }
            if(!q.empty())
                minutes++;
        }
        if(count == totalOranges)
            return minutes;
        return -1;
    }
};