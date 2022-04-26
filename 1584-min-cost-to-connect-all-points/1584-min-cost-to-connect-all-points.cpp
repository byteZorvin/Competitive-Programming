class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> mst(n, false);
        minDist[0] = 0;
        
        int remaining = 0, minCost = 0;
        while(remaining<n) {            
            int currNode = -1;
            for(int node = 0; node<n; node++) {
                if (!mst[node] & (currNode == -1 || minDist[currNode]>minDist[node]))
                    currNode = node;
            }
            mst[currNode] = true;
            minCost += minDist[currNode];
            remaining++;
            
            for(int nextNode = 0; nextNode < n; nextNode++) {
                if(mst[nextNode]) continue;
                int weight = abs(points[currNode][0] - points[nextNode][0]) +
                                abs(points[currNode][1] - points[nextNode][1]);
                minDist[nextNode] = min(minDist[nextNode], weight);
            }
        }
        return minCost;
    }
};