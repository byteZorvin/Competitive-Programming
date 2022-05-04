class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int pairs = 0;
        for(auto &x: nums) {
            if(freq[k-x]) 
                freq[k-x]--, pairs++;
            else freq[x]++;
        }
        return pairs;
    }
};