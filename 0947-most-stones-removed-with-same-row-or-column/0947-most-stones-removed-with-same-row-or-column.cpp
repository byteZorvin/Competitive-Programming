class Solution {
    void dfs(vector<vector<int>> &adjRow, 
             vector<vector<int>> &adjCol,
             int x, int y, 
             vector<vector<bool>>& visited
            ) {
        
        visited[x][y] = true;
        for(int j = 0; j<adjRow[x].size(); j++) {
            int y = adjRow[x][j];
            if(!visited[x][y])
                dfs(adjRow, adjCol, x, y, visited);
        }
        for(int i = 0; i<adjCol[y].size(); i++) {
            int x = adjCol[y][i];
            if(!visited[x][y]) 
                dfs(adjRow, adjCol, x, y, visited);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = stones.size();
        vector<vector<int>> adjRow(10001), adjCol(10001);
        for(int i = 0; i<m; i++) {
            int x = stones[i][0], y = stones[i][1];
            adjRow[x].push_back(y);
            adjCol[y].push_back(x);
        }
        vector<vector<bool>> visited(10001, vector<bool>(10001, false));
        int count = 0;
        for(int i = 0; i<adjRow.size(); i++) {
            for(int j = 0; j<adjRow[i].size(); j++) {
                int x = i, y = adjRow[i][j];
                if(!visited[x][y]) {
                    dfs(adjRow, adjCol, x, y, visited);
                    count++;
                }
            }
        }
        return m - count;
    }
};