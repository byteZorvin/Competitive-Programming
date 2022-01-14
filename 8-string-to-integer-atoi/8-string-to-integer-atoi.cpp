class Solution {
private:
    bool isDigit(char &c) {
        return c<='9' && c>='0';
    }
public:
    int myAtoi(string s) {
        int n = s.size();
        int ans = 0, i = 0, sign = 1;

        while(i<n && s[i] == ' ') i++;
        if(s[i] == '-') sign = -1, i++;  
        else if(s[i] == '+') i++;
        
        while(i<n && isDigit(s[i])) {
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i] - '0' > 7)) {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ans = ans*10 + (s[i] - '0');
            i++;
        }
        
        return ans*sign;
    }
};