class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++) {
            freq[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto &t : freq) {
            pq.push(t.second);
        }
        int count = 0, half = n/2;
        while(n>half) {
            int top = pq.top();
            n -= top;
            pq.pop();
            count++;
        }
        return count;
    }
};