class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto &c: ransomNote) {
            mp[c]++;
        }
        for(auto &c: magazine) {
            if(mp.find(c) != mp.end()) {
                mp[c]--;
                if(mp[c] == 0) 
                    mp.erase(c);
                if(mp.empty()) 
                    return true;
            }
        }
        return false;
    }
};