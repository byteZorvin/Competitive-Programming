class Solution {
    vector<vector<vector<int>>>dp;
    int findMaxSubset(vector<string>&strs, int m, int n, int i) {
        if(i<0) return 0;
        
        if(dp[i][m][n] != -1) return dp[i][m][n];
        
        int zeroCount = count(strs[i].begin(), strs[i].end(), '0');
        int oneCount = strs[i].size() - zeroCount;
        
        int include = 0, notInclude = 0;
        if(m>=zeroCount && n>=oneCount) 
            include = 1 + findMaxSubset(strs, m - zeroCount, n - oneCount, i - 1);
        notInclude = findMaxSubset(strs, m, n, i - 1);
        
        return dp[i][m][n] = max(include, notInclude);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return findMaxSubset(strs, m, n, strs.size() - 1);
    }
};