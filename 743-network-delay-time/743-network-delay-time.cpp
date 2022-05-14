class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &time: times) 
            adj[time[0]].push_back({time[2], time[1]});
        
        
        vector<int> signalRecieved(n+1, 1e7);
        signalRecieved[k] = 0;
        
        queue<int> q;
        q.push(k);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i<n; i++) {
                int currNode = q.front();
                q.pop();
                
                int now = signalRecieved[currNode];
                
                for(auto &edge: adj[currNode]) {
                    int neighbour = edge.second;
                    int timeReq = edge.first;
                    if(signalRecieved[neighbour] > now + timeReq) 
                        signalRecieved[neighbour] = now + timeReq,
                        q.push(neighbour);
                }
            }
        }
        
        int answer = 0;
        for(int node = 1; node <= n; node++) 
            answer = max(answer, signalRecieved[node]);
        
        return answer == 1e7 ? -1 : answer;
    }
};