class Solution {
public:
    string interpret(string s) {
        string ans;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == 'G') {
                ans += 'G';
            }else if(s[i] == '(') {
                if(s[i+1] == ')') {
                    ans += 'o';
                    i++;
                }
                else {
                    ans += "al";
                    i += 3;
                }
            }
        }
        return ans;
    }
};