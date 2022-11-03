class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int unpaired = 0, ans = 0;
        for(auto w: words) {
            if(w[0] == w[1]) {
                if(m[w]>0) {
                    m[w]--;
                    unpaired--;
                    ans += 4;
                }
                else m[w]++, unpaired++;
            }
            else {
                string rev = w;
                reverse(rev.begin(), rev.end());
                if(m[rev] > 0) {
                    m[rev]--;
                    ans += 4;
                }
                else m[w]++;
            }
        }
        if(unpaired) ans += 2;
        return ans;
    }
};