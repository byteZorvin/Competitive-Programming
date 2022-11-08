class Solution {
public:
    int numDistinct(string s, string t) {
        long long n = s.size(), m = t.size();
        vector<unsigned long long>cur(m+1, 0);
        cur[0] = 1;

        for(long long i = 1; i<=n; i++) {
            for(long long j = m; j>=1; j--) {
                if(s[i-1] == t[j-1]) {
                    cur[j] = cur[j] + cur[j-1];
                }
            }
        }
        
        return cur[m];
    }
};