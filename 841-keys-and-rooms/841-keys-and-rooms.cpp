class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), opened = 0;
        vector<bool> vis(n, false);
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            opened++;
            
            for(auto &r: rooms[front]) {
                if(!vis[r]) 
                    q.push(r), vis[r] = true;
            }
        }
        
        return opened == n;
    }
};