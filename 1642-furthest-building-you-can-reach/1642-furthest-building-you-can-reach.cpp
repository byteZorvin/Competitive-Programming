class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i = 1; i<heights.size(); i++) {
            int diff = heights[i] - heights[i-1];
            if(diff > 0) {
                pq.push(diff);
                if(pq.size()>ladders) {
                    sum += pq.top();
                    pq.pop();
                }
            }
            if(sum>bricks) 
                return i-1;
        }
        return i-1;
    }
};