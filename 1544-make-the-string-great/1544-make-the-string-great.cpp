class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        for(int j = 0; j<s.size(); j++) {
            if(i>0 and abs(s[i-1]-s[j]) == 32) i--;
            else {
                s[i] = s[j];
                i++;
            }
        }
        return s.substr(0, i);
    }
};