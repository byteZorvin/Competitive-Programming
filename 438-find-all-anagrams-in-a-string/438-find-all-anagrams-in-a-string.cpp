class Solution {
private:
    bool checkAnagram(string &s, string &p, int start) {
        int ch[26] = {0};
        for(int i = 0; i<p.size(); i++) {
            ch[s[i + start] - 'a']++;
            ch[p[i] - 'a']--;
        }
        return count_if(begin(ch), end(ch), [](int i){ return i != 0; }) == 0;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indexes;
        int n = s.size(), m = p.size();
        for(int i = 0; i+m-1<n; i++) {
            if(checkAnagram(s, p, i)) 
                indexes.push_back(i);
        }
        return indexes;
    }
};