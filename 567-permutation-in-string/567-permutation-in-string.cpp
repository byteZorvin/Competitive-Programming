class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        int m = s1.size(), n = s2.size();
        
        if(m>n) return false;
        
        int j = 0;
        for(int i = 0; i<n; i++) {
            if(i<m) {
                mp[s2[i]]++;
                mp[s1[i]]--;
                 
                if(mp[s2[i]] == 0) mp.erase(s2[i]);
                if(mp[s1[i]] == 0) mp.erase(s1[i]);
            }
            else {
                if(mp.empty()) return 1;
            
                mp[s2[j]]--;
                if(mp[s2[j]] == 0) mp.erase(s2[j]);

                j++;

                mp[s2[i]]++;
                if(mp[s2[i]] == 0) mp.erase(s2[i]);
            }
        }
        return mp.empty();
    }
};