class Solution {
    bool BipartiteUtil(vector<vector<int>>&graph, int src, vector<int>&color) {
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(auto adj: graph[u]) {
                if(color[adj] == -1) 
                    color[adj] = color[u]^1, q.push(adj);
                else if((color[adj]^color[u]) == 0) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++) {
            if(color[i] == -1 && !BipartiteUtil(graph, i, color)) return false;
        }
        return true;
    }
};