class Solution {
public:
    void dijkstra(int row, int col, int n, int m, vector<vector<int>>& heights, int &absDiff)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0, {row, col}});

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!pq.empty())
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();
            
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            
            if(i == n-1 && j == m-1)
            {
                absDiff = diff;
                break;
            }
            
            for(int k=0; k<4; k++)
            {
                int x = dx[k] + i;
                int y = dy[k] + j;
                
                if(x >= 0 && y>=0 && x<n && y<m && !vis[x][y])
                {   
                    int CurrDiff = max(diff, abs(heights[x][y] - heights[i][j]));
                    pq.push({CurrDiff, {x, y}});
                }   
            }
        }
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int absDiff = INT_MAX;
        dijkstra(0, 0, heights.size(), heights[0].size(), heights, absDiff);
        return absDiff;
    }
};