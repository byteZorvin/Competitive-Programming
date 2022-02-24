class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if(m != n) return false;
        int ch[26] = {0};
        for(int i = 0; i<n; i++) {
            ch[s[i]-'a']++;
            ch[t[i]-'a']--;
        }
        for(int i = 0; i<26; i++) {
            if(ch[i] != 0) return false;
        }
        return true;
    }
};