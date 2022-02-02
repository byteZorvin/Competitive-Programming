class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>sm, pm;
        for(auto &ch: p) pm[ch]++;
        
        vector<int> indices;
        int j = 0, n = s.size(), m = p.size(), perfect = 0;
        for(int i = 0; i<n; i++) {
            sm[s[i]]++;
            if(i-j+1 == m) {
                if(sm == pm)
                    indices.push_back(j);
                sm[s[j]]--;
                if(sm[s[j]] == 0) 
                    sm.erase(s[j]);
                j++;
            }
        }
        return indices;
    }
};