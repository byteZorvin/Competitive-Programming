class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> m(26, vector<int>(26, 0));
        int ans = 0;
        for(auto &w: words) {
            int a = w[0] - 'a', b = w[1] - 'a';
            if(m[b][a] > 0) m[b][a]--, ans += 4;
            else m[a][b]++;
        }
        for(int i = 0; i<26; i++) {
            if(m[i][i]>0){
                ans += 2;
                break;
            } 
        }
        return ans;
    }
};