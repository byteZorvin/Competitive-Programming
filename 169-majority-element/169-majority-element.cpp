class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int candidate = -1, votes = 1, n = arr.size(); 
        for(int i = 0; i<n; i++) {
            if(arr[i] != candidate) {
                votes--;
                if(votes == 0) {
                    votes = 1;
                    candidate = arr[i];
                }
            }
            else votes++;
        }
        return candidate;
    }
};