class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for(auto &c: s) {
            freq[c]++;
        }
        for(int i = 0; i<n; i++) {
            if(freq[s[i]] == 1)
                return i;
        }
        return -1;
    }
};