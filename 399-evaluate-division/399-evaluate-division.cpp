class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double queryAns;
public:
    bool dfs(string up, string down, double runningProduct) {
        if(up == down && adj.find(up) != adj.end()) {
            queryAns = runningProduct;
            return true;
        }
        bool tempAns = false;
        visited[up] = true;
        for(auto &e: adj[up]) {
            string s = e.first;
            if(visited[s]) continue;
            tempAns = dfs(s, down, runningProduct*e.second);
            if(tempAns) {
                break;
            } 
        }
        visited[up] = false;
        return tempAns;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        for(int i = 0; i<n; i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            visited[equations[i][0]] = 0;
            visited[equations[i][1]] = 0;
        }
        
        for(int i = 0; i<m; i++) {
            bool res = dfs(queries[i][0], queries[i][1], 1);
            if(res) ans[i] = queryAns;
            else ans[i] = -1;
        }
        return ans;
    }
};