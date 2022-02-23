class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, n = s.size();
        set<char> seen;
        for(int j = 0; j<n; j++) {
            if(seen.find(s[j]) != seen.end()) {
                ans = max(ans, j-i);
                while(i<j)
                {
                    seen.erase(s[i]);
                    if(s[i] == s[j]) {
                        i++;
                        break;
                    }
                    i++;
                }
            }
            seen.insert(s[j]);
        }
        for(auto &i: seen) {
            cout << "somethin" << i << '\n';
        }
        return max(ans, n-i);
    }
};