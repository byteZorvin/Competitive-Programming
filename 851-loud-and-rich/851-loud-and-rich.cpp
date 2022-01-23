class Solution {
private:
    void dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<bool> &vis, int i, vector<int> &ans) {
        vis[i] = true;
        ans[i] = i;
        
        for(auto &richer: graph[i]) {
            if(!vis[richer]) {
                dfs(graph, quiet, vis, richer, ans);
            }
            if(quiet[ans[i]] > quiet[ans[richer]])
                ans[i] = ans[richer];
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for(auto &e: richer) {
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> ans(n);
        vector<bool> vis(n, false);
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                dfs(graph, quiet, vis, i, ans);
            }
        }
        return ans;
    }
};