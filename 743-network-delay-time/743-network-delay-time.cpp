class Solution {
    void DFS(vector<vector<pair<int, int>>> &adj, int currNode, 
             int time, vector<int>&signalRecieved)
    {   
        if(time >= signalRecieved[currNode])
            return;
        
        signalRecieved[currNode] = time;
        
        for(auto &edge: adj[currNode])
            DFS(adj, edge.second, edge.first + time, signalRecieved);  
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time: times) 
            adj[time[0]].push_back({time[2], time[1]});
        
        for(int i = 1; i<=n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        vector<int> signalRecieved(n+1, 1e7);
        DFS(adj, k, 0, signalRecieved);
        
        int answer = 0;
        for(int node = 1; node <= n; node++) 
            answer = max(answer, signalRecieved[node]);
        
        return answer == 1e7 ? -1 : answer;
    }
};