class Solution {
    vector<string>ans;
    void helper(string &s, int i) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }
        helper(s, i+1);
        if(s[i]<='z' && s[i]>='a') {
            s[i] = toupper(s[i]);
            helper(s, i+1);
            s[i] = tolower(s[i]);
        } 
    }
public:
    vector<string> letterCasePermutation(string s) {
        for(auto &c : s) 
            c = tolower(c);
        helper(s, 0);
        return ans;
    }
};