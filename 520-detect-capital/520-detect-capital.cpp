class Solution {
private:
    bool Cap(char &c) {
        return c>='A' and c<='Z';
    }
    
    bool small(char &c) {
        return c>='a' and c<='z';
    }
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        
        int cpcnt = 0, smcnt = 0;
        for(int i = 0; i<n; i++) {
            if(Cap(word[i]))
                cpcnt++;
            else if(small(word[i]))
                smcnt++;
        }
        return cpcnt == n or smcnt == n or (Cap(word[0]) and smcnt == n-1);
    }
};