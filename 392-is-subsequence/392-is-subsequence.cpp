class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        if(m == 0) return true;
        if(n<m) return false;
        int j = 0;
        for(int i = 0; i<n; i++) {
            if(s[j] == t[i]) j++;
            if(j == m) return true;
        }
        return false;
    }
};