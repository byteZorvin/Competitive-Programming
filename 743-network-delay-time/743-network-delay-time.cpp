class Solution {
    void dijkstra(vector<int> &signalRecieved, int source, vector<vector<pair<int, int>>> &adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> q;
        q.push({0, source});
        while(!q.empty()) {
            int currNodeTime = q.top().first;
            int currNode = q.top().second;
            q.pop();

            if(currNodeTime > signalRecieved[currNode]) continue;

            for(auto &edge: adj[currNode]) {
                int neighbour = edge.second;
                int timeReq = edge.first;
                if(signalRecieved[neighbour] > currNodeTime + timeReq) 
                    signalRecieved[neighbour] = currNodeTime + timeReq,
                    q.push({currNodeTime + timeReq, neighbour});
            }
        }
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time: times) 
            adj[time[0]].push_back({time[2], time[1]});
        
        
        vector<int> signalRecieved(n+1, 1e7);
        signalRecieved[k] = 0;
        
        dijkstra(signalRecieved, k, adj);
        
        int answer = 0;
        for(int node = 1; node <= n; node++) 
            answer = max(answer, signalRecieved[node]);
        
        return answer == 1e7 ? -1 : answer;
    }
};