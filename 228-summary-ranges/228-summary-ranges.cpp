class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        int start = nums[0], end = nums[0];
        vector<string> ans;
        for(int i = 1; i<n; i++) {
            if(nums[i] == end + 1) {
                end++;
            }
            else {
                if(start == end) {
                    ans.push_back(to_string(start));
                }
                else {
                    string s = to_string(start);
                    s += "->";
                    s += to_string(end);
                    ans.push_back(s);
                }
                start = end = nums[i];
            }
        }
        if(start == end) {
            ans.push_back(to_string(start));
        }
        else {
            string s = to_string(start);
            s += "->";
            s += to_string(end);
            ans.push_back(s);
        }
        return ans;
    }
};