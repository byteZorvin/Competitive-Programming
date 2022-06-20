class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for(auto &s: words) {
            for(int i = 1; i<s.length(); i++) {
                good.erase(s.substr(i));
            }
        }
        int ans = 0;
        for(auto &s: good) 
            ans += s.length() + 1;
        return ans;
    }
}; 