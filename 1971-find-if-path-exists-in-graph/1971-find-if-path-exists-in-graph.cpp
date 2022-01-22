class Solution {
private:
    bool dfs(vector<vector<int>> &adj, int src, int desti, vector<bool> &vis) {
        if(desti == src) return true;
        vis[src] = true;
        
        for(auto &node: adj[src]) {
            if(!vis[node] && dfs(adj, node, desti, vis))
                return true; 
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(adj, source, destination, visited);
    }
};