class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q; q.push(beginWord);
        int steps = 0;
        
        while(!q.empty()) {
            steps++;
            int sz = q.size();
            for(int i = 0; i<sz; i++) {
                string x = q.front();
                q.pop();
                
                if(x == endWord) return steps;
                
                for(int j = 0; j<x.size(); j++) {
                    char c = x[j];
                    for(int k = 0; k<26; k++) {
                        x[j] = 'a' + k;
                        if(dict.find(x) != dict.end()) {
                            dict.erase(x);
                            q.push(x);
                        }
                    }
                    x[j] = c;
                }
            }
        }
        return 0;
    }
};