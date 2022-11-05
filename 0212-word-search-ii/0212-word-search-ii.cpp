class TrieNode {
public:
    bool ends;
    vector<TrieNode*>children;
    
    TrieNode(): ends(false), children(vector<TrieNode*>(26, NULL)) {}
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode*cur = root;
        for(int i = 0; i<n; i++) {
            int c = word[i] - 'a';
            if(cur->children[c] == NULL) {
                TrieNode* newNode = new TrieNode();
                cur->children[c] = newNode;
            }
            cur = cur->children[c];
        }
        cur->ends = true;
    }
};

class Solution {
    void dfs(vector<vector<char>>&board, int i, int j, string curr, TrieNode*node, vector<string>&ans) {
        char c = board[i][j];
        if(c == '#' or node->children[c-'a'] == NULL) return;
        curr += c;
        node = node->children[c-'a'];
        if(node->ends){
            ans.push_back(curr);
            node->ends = false;
        } 
        board[i][j] = '#';
        
        if(i>0) dfs(board, i-1, j, curr, node, ans);
        if(j>0) dfs(board, i, j-1, curr, node, ans);
        if(i+1<board.size()) dfs(board, i+1, j, curr, node, ans);
        if(j+1<board[0].size()) dfs(board, i, j+1, curr, node, ans);
        
        board[i][j] = c;   
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie* trie = new Trie;
        TrieNode* root = trie->root;
        for(auto w: words) 
            trie->insert(w);
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                dfs(board, i, j, "", root, ans);
            }
        }
        return ans;
    }
};