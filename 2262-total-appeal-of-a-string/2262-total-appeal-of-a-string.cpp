class Solution {
public:
    long long appealSum(string s) {
        vector<int>last(26, -1);
        long long res = 0, prev = 0;
        for(int i = 0; i<s.size(); i++) {
            prev = prev + (i+1 - (last[s[i]-'a']+1));
            res += prev;
            last[s[i]-'a'] = i;
        }
        return res;
    }
};