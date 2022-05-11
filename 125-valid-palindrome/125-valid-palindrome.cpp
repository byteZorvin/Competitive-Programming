class Solution {
    bool checkPalinHelper(string &s) {
        int i = 0, j = s.size()-1;
        while(i<j) {
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string candidate;
        for(auto &c: s) {
            c = tolower(c);
            if(c>='0' && c<='9')
                candidate += c;
            else if(c >= 'a' && c <= 'z') 
                candidate += tolower(c);
        }
        return checkPalinHelper(candidate);
    }
};