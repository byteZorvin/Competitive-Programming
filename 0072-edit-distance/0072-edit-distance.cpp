class Solution {
    int helper(string &w1, string &w2, int i, int j, vector<vector<int>> &dp) {
        //base case
        if(dp[i][j] != -1) return dp[i][j];
        if(j == w2.size()) return w1.size() - i;
        if(i == w1.size()) return w2.size() - j;
        
        if(w1[i] == w2[j]) return dp[i][j] = helper(w1, w2, i+1, j+1, dp);
        else 
            return dp[i][j] =  1 + min({
                            helper(w1, w2, i+1, j, dp), 
                            helper(w1, w2, i, j+1, dp), 
                            helper(w1, w2, i+1, j+1, dp)
                        });
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // insert -> j++
        // delete -> i++
        // replace -> i++, j++
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(word1, word2, 0, 0, dp);
    }
};