class Solution {
public:
    int scoreOfParentheses(string s) {
        int l = 0, ans = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') l++;
            else {
                l--;
                if(s[i-1] == '(') ans += (1<<l);
            }
        }
        return ans;
    }
};