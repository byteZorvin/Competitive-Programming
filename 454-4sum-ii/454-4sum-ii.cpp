class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int>m1, m2;
        int n = nums1.size();
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                m1[nums1[i] + nums2[j]]++;
                m2[nums3[i] + nums4[j]]++;
            }
        }
       
        int count = 0;
        for(auto s: m1) {
            auto it = m2.find(-(s.first));
            if(it != m2.end()) {
               count += (s.second)*(it->second);
            }
        }
        return count;
    }
};