class Solution {
public:
    int numDistinct(string s, string t) {
        long long n = s.size(), m = t.size();
        vector<unsigned long long>prev(m+1, 0), cur(m+1, 0);
        prev[0] = 1, cur[0] = 1;

        for(long long i = 1; i<=n; i++) {
            for(long long j = 1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    cur[j] = prev[j-1] + prev[j];
                }
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        
        return cur[m];
    }
};