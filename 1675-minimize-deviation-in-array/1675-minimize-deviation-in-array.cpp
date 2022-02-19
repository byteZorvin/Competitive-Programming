class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, mini = INT_MAX;
        priority_queue<int> pq; // in C++ default if max heap
        for(auto &i: nums) {
            if(i%2) i *= 2;
            pq.push(i);
            mini = min(i, mini);
        }
        while(pq.top()%2 == 0) {
            ans = min(ans, pq.top() - mini);
            mini = min(mini, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(ans, pq.top()-mini);
    }
};