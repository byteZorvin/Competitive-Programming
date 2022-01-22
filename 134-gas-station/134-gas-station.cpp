class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0, n = gas.size(), due = 0, start = 0;
        for(int i = 0; i<n; i++) {
            if(curr+gas[i] < cost[i]) {
                due += curr + gas[i] - cost[i];
                start = i+1;
                curr = 0;
            }
            else
                curr += (gas[i] - cost[i]);
        }
        return curr + due>=0 ? start : -1;
    }
};