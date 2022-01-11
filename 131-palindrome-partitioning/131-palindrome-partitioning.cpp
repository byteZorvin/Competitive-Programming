class Solution {
private:
    bool checkPalindrome(string &s, int start, int end) {
        while(start<end) {
            if(s[start++] != s[end--]) 
                return false;
        }
        return true;
    }
private:
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currList) {
        if(start == s.size()) {
            result.push_back(currList);
            return;
        }
        for(int end = start; end<s.size(); end++) {
            if(checkPalindrome(s, start, end)) {
                currList.push_back(s.substr(start, end-start+1));
                dfs(result, s, end+1, currList);
                currList.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> currList;
        vector<vector<string>> result;
        dfs(result, s, 0, currList);
        return result;
    }
};