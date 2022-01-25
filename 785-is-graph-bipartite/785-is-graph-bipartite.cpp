class Solution {
    bool BipartiteUtil(vector<vector<int>> &graph, int src, vector<int> &color) {
        color[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int &v: graph[u]) {
                if(color[v] == -1) 
                    color[v] = color[u]^1, q.push(v);
                else if(color[u]^color[v] == 0) return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i<n; i++) {
            if(color[i] == -1) 
                if(!BipartiteUtil(graph, i, color)) return false;
        }
        return true;
    }
};