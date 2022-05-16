class Solution {
    bool isValid(vector<vector<int>>& grid, int r, int c) {
        return r>=0 && r<grid.size() && c >= 0 && c < grid[0].size()
             && grid[r][c] == 0;
    }
    
    int BFS(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1}, 
            {1, -1},  {1, 0},  {1, 1}
        };
        queue<pair<int, int>> q;
        if(isValid(grid, 0, 0))
            q.push({0, 0});
        
        int distance = 0;
        
        while(!q.empty()) {
            int x = q.size();
            distance++;
            for(int i = 0; i<x; i++) {
                auto [r, c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1) return distance;
                
                for(auto &dir: dirs) {
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    if(!isValid(grid, new_r, new_c)) continue;
                    q.push({new_r, new_c});
                    grid[new_r][new_c] = 1;
                }
            }  
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return BFS(grid);
    }
};