class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        
        string a, b;
        vector<int> fa(26), fb(26);
        int n = word1.size();
        for(int i = 0; i<n; i++) {
            char c1 = word1[i], c2 = word2[i];
            if(fa[c1 - 'a']++ == 0) 
                a += c1;
            if(fb[c2 - 'a']++ == 0) 
                b += c2;
        }
        sort(fa.begin(), fa.end());
        sort(fb.begin(), fb.end());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a != b) return false;
        for(int i = 0; i<26; i++) {
            if(fa[i] != fb[i]) return false;
        }
        return true;
    }
};