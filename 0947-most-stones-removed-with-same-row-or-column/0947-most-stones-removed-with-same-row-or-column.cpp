class Solution {
    void dfs(vector<vector<int>> &adjRow, vector<vector<int>> &adjCol, int x, int y, 
             vector<vector<bool>>& visited) {
        
        visited[x][y] = true;
        
        for(auto j: adjRow[x]) {
            if(!visited[x][j])  
                dfs(adjRow, adjCol, x, j, visited);
        }
        
        for(auto i: adjCol[y]) {
            if(!visited[i][y])
                dfs(adjRow, adjCol, i, y, visited);
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
        for(int i=0; i<adjRow.size(); i++){
            for(int j=0; j<adjRow[i].size(); j++){
                
                if(!visited[i][adjRow[i][j]]) 
                    dfs(adjRow, adjCol, i, adjRow[i][j], visited), count++;
            }
        }
        return m - count;
    }
};