class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Ch[256] = {0};
        int ans = 0, j = 0;
        for(int i = 0; i<s.size(); i++) {
            char c = s[i];
            if(Ch[c]) {
                while(s[j] != c) {
                    Ch[s[j]] = 0;
                    j++;
                }
                j++;
            }
            else {
                ans = max(i-j+1, ans);
                Ch[c] = 1;
            }
        }
        return ans;
    }
};