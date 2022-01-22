class Solution {
private:
    vector<int> recSt;
    vector<vector<int>> paths;
    
private:
    void dfs(vector<vector<int>> &graph, int src) {
        if(src == graph.size() - 1) {
            paths.push_back(recSt);
            return;
        }
        
        for(int &node: graph[src]) {
            recSt.push_back(node);
            dfs(graph, node);
            recSt.pop_back();
        }
    }
 
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        recSt.push_back(0);
        dfs(graph, 0);
        return paths;
    }
};