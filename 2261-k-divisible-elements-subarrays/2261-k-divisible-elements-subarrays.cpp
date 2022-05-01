class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            vector<int>subarr;
            int count = 0;
            for(int j = i; j<n; j++) {
                subarr.push_back(nums[j]);
                count += (nums[j]%p == 0);
                if(count <= k) ans.insert(subarr);
                else break;
            }
        }
        return ans.size();
    }
};