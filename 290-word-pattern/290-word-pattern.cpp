class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int n = s.size();
        
        string curr = "";
        for(int i = 0; i<n; i++) {
            if(s[i] == ' ') {
                words.push_back(curr);
                curr = "";
            }
            else 
                curr += s[i];
        }
        if(!curr.empty()) words.push_back(curr);
        if(words.size() != pattern.size()) return false;
        unordered_set<string> available(words.begin(), words.end());
        
        unordered_map<char, string> bijection;
        for(int i = 0; i<words.size(); i++) {
            auto itr = bijection.find(pattern[i]);
            if(itr != bijection.end()) {
                if(itr->second != words[i]) return 0;
            }
            else {
                if(available.find(words[i]) == available.end()) return 0;
                bijection[pattern[i]] = words[i];
                available.erase(words[i]);
            }
        }
        return 1;
    }
};