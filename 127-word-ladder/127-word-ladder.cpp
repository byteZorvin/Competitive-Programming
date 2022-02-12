class Solution {
private:
    void Makegraph(vector<string>& wordList, vector<vector<int>>& adj, unordered_map<string, int>& s) {
        int n = wordList.size(), m = wordList[0].size();
        s.insert({wordList[0], 0});
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                string str = wordList[i];
                char c = str[j];
                for(int k = 0; k<26; k++) {
                    if(c == 'a' + k) continue;
                    str[j] = 'a' + k;
                    auto it = s.find(str);
                    if(it != s.end())
                        adj[i].push_back(it->second), adj[it->second].push_back(i);
                }
            }
            s.insert({wordList[i], i});
        }
    }
private:
    int ShortestPath(vector<string>& wordList, vector<bool>& vis, string endWord, vector<vector<int>>& adj) {
        queue<int> q;
        int n = wordList.size();
        q.push(n-1);
        vis[n-1] = true;
        
        int steps = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            steps++;
            for(int i = 0; i<sz; i++) {
                int x = q.front();
                q.pop();
                
                if(wordList[x] == endWord) {
                    return steps;
                }
                
                for(auto &w: adj[x]) {
                    if(!vis[w]) {
                        vis[w] = 1;
                        q.push(w);
                    }
                }
            }
        }
        
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> adj(n);
        unordered_map<string, int> s; 
        Makegraph(wordList, adj, s);
        vector<bool> vis(n, false);
        return ShortestPath(wordList, vis, endWord, adj);
    }
};