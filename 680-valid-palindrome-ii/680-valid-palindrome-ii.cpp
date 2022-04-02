class Solution {
    bool helper(string &s, int l, int h, bool deleted) {
        if(l>=h) return true;
        if(s[l] != s[h]) {
            if(deleted) return false;
            else return helper(s, l+1, h, true) || helper(s, l, h-1, true);
        }
        else return helper(s, l+1, h-1, deleted);
    }
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size()-1, false);
    }
};