class TrieNode {
public:
    bool ends;
    TrieNode* children[26];
    
    TrieNode() {
        for(int i = 0; i<26; i++) {
            children[i] = NULL;
        }
        ends = false;
    }
};

class Trie {
    TrieNode *root;
public:
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
    
    bool search(string word) {
        int i = 0; 
        TrieNode* cur = root;
        while(i<word.size()) {
            int c = word[i] - 'a';
            if(cur->children[c] == NULL){
                return false;
            }
            cur = cur->children[c];
            i++;
        }
        return cur->ends;
    }
    
    bool startsWith(string word) {
        int i = 0;
        TrieNode* cur = root;
        while(i<word.size()) {
            int c = word[i] - 'a';
            if(cur->children[c] == NULL) return false;
            cur = cur->children[c];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */