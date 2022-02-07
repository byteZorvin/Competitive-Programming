class Solution {
public:
    char findTheDifference(string s, string t) {
        int ch[26] = {0};
        for(auto &c: s)
            ch[c-'a']++;
        for(auto &c: t)
            ch[c-'a']--;
        for(int i = 0; i<26; i++) 
            if(ch[i]<0)
                return 'a' + i;
        return -1;
    }
};