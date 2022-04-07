class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(!pq.empty()) {
            int a = pq.top(); pq.pop();
            if(pq.empty()) return a;
            int b = pq.top(); pq.pop();
            if(a == b) continue;
            pq.push(abs(a-b));
        }
        return 0;
    }
};