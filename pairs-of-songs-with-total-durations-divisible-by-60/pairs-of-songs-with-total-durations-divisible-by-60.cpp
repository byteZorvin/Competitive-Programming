class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> remainder;
        int n = time.size();
        int pairs = 0;
        
        for(int i = 0; i<n; i++) {
            int rem = time[i]%60;
            int complementary = (60-rem)%60;
            
            if(remainder.find(complementary)!= remainder.end()) 
                pairs += remainder[complementary];
            remainder[rem]++;
        }
        
        return pairs;
    }
};