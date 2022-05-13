class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel = 0, start = 0, n = gas.size();
        int mini = 0;
        for(int i = 0; i<n; i++) {
            fuel += gas[i] - cost[i];
            if(fuel < mini) {
                mini = fuel;
                start = (i + 1) % n;
            }
        }
        return fuel >= 0 ? start : -1;
    }
};