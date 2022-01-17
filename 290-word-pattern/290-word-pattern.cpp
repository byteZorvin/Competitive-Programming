class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream str(s);
        unordered_map<string, int> s2i;
        unordered_map<char, int> c2i;
        int i = 1, n = pattern.size();
          
        for(string word; str>>word; i++) {
            if(i==n+1 || s2i[word] != c2i[pattern[i-1]]) 
                return false;
            s2i[word] = c2i[pattern[i-1]] = i;
        }
        return i==n+1;
    }
};