class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        int n = strs.size();
        for(int i = 0; i<n; i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            groups[word].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto &group : groups) 
            ans.push_back(group.second);
        return ans;
    }
};