class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1, votes = 0, n = arr.size(); 
        for(int i = 0; i<n; i++) {
            if(votes == 0) {
                candidate = arr[i];
            }
            votes += (candidate == arr[i]) ? 1: -1;
        }
        return candidate;
    }
};