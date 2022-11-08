class Solution {
    string helper(string s) {
        int n = s.size();
        int i = 0;
        
        string ans;
        for(i = 0; i<n-1; i++) {
            if(tolower(s[i]) == tolower(s[i+1]) && s[i] != s[i+1])
                i++;
            else ans += s[i];
        }
        if(i == n-1) 
            ans += s[i];
        
        return ans;
    }
public:
    string makeGood(string s) {
        string ans = helper(s);
        while(s != ans) {
            s = ans; 
            ans = helper(s);
        }
        return ans;
    }
};