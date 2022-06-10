class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexes;
        int len = 0, left = 0;
        for(int i = 0; i<s.size(); i++) {
            if(indexes.find(s[i]) != indexes.end()) 
                left = max(left, indexes[s[i]]+1);
            len = max(len, i-left+1);
            indexes[s[i]] = i;
        }
        return len;
    }
};