class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool vis[26] = {0};
        int last[26] = {0};
        
        int n = s.size();
        for(int i = 0; i<n; i++) last[s[i]-'a'] = i;
        
        string res;
        for(int i = 0; i<n; i++) {
            if(vis[s[i]-'a']) continue;
            while(!res.empty() && res.back() > s[i] && last[res.back() - 'a'] > i) {
                vis[res.back()-'a'] = 0;
                res.pop_back();
            }
            vis[s[i]-'a'] = 1;
            res.push_back(s[i]);
        }
        return res;
    }
};