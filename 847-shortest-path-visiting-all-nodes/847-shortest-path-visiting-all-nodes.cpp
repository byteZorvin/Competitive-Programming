class Solution {
public:
    class Tuple {
        public:
            int node, mask, cost;
        Tuple(int node, int mask, int cost) {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>>seen(n+1, vector<bool>(1<<n, false));
        queue<Tuple> q;
        
        for(int i = 0; i<n; i++) {
            seen[i][1<<i] = true;
            q.push(Tuple (i, 1<<i, 0));
        }
                                 
        while(!q.empty()) {
            Tuple cur = q.front();
            q.pop();
            
            if(cur.mask == (1<<n)-1) return cur.cost;
            
            for(auto &child: graph[cur.node]) {
                int bitMask = cur.mask;
                bitMask |= (1<<child);
                if(!seen[child][bitMask]) {
                    seen[child][bitMask] = true;
                    q.push(Tuple (child, bitMask, cur.cost + 1));
                }
            }
        }
        return -1;
    }
};