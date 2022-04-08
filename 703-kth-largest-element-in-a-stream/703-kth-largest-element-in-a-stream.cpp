class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for(auto &i: nums) {
            pq.push(i);
            if(pq.size()>x) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>x) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */