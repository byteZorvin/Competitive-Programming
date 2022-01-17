class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream str(s);
        unordered_map<string, int> s2i;
        unordered_map<char, int> c2i;
        int i, n = pattern.size();
        for(string word; str>>word; i++) {
            if(i==n || s2i[word] != c2i[pattern[i]]) 
                return false;
            s2i[word] = c2i[pattern[i]] = i+1;
        }
        return i==n;
    }
};