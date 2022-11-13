class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string w;
        while(ss>>w) {
            words.push_back(w);
        }
        string ans;
        for(int i = words.size()-1; i>=0; i--) {
            ans += words[i];
            if(i>0) ans += ' ';
        }
        return ans;
    }
};