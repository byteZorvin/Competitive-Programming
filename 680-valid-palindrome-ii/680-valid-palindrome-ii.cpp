class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, h = s.size()-1;
        while(l<h) {
            if(s[l] == s[h]) l++, h--;
            else {
                int x = l, y = h-1;
                bool first = true, second = true;
                while(x<y) {
                    if(s[x] != s[y]) {
                        first = false; 
                        break;
                    }
                    x++, y--;
                }
                x = l+1, y = h;
                while(x<y) {
                    if(s[x] != s[y]) {
                        second = false;
                        break; 
                    } 
                    x++, y--;
                }
                return first || second; 
            }
        }
        return true;
    }
};