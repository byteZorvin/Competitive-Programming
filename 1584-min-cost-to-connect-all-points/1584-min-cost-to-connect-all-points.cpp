class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<bool> mst(n, false);
        heap.push({0, 0});
        
        int remaining = 0, minCost = 0;
        while(remaining<n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            if(mst[currNode]) continue;
            
            mst[currNode] = true;
            minCost += weight;
            remaining++;
            
            for(int nextNode = 0; nextNode < n; nextNode++) {
                if(mst[nextNode]) continue;
                int weight = abs(points[currNode][0] - points[nextNode][0]) +
                                abs(points[currNode][1] - points[nextNode][1]);
                heap.push({weight, nextNode});
            }
        }
        return minCost;
    }
};