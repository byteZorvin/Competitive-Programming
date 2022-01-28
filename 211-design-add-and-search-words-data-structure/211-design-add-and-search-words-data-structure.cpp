class WordDictionary {
public:
    struct Node{
        char c;
        int end; //for marking the end of a string
        
        Node* child[26];
    };
    Node *get_node_to_insert(char c){
        Node * new_node = new Node;
        new_node->c = c;
        new_node->end=0;
        for(int i=0; i<26; i++){
            new_node->child[i]=NULL;
        }
        return new_node;
    }
    Node *root=get_node_to_insert('/');
    void insert_in_trie(string s){
        int i, j;
        Node *curr = root;
        while(s[i]){
            j = s[i]-'a';
            if(curr->child[j] == NULL){
                curr->child[j]=get_node_to_insert(s[i]);
            }
            curr=curr->child[j];
            i++;
        }
        curr->end=1;
    }
    bool search_trie(string s, Node* curr, int position, int n){
        if(s[position]=='.'){
            Node * current = curr;
            bool  res=0;
            for(int i=0; i<26; i++){
                if(position==n-1 and curr->child[i]){
                    current = curr->child[i];
                    res |= current->end==1? 1: 0;
                }
                else if(curr->child[i] and search_trie(s, curr->child[i], position+1, n))
                    return 1;
            }
            return res;
        }
        else if(curr->child[s[position]- 'a']){
            if(position==n-1){
                curr = curr->child[s[position]-'a'];
                return curr->end==1 ? 1:0;
            }
            return search_trie(s, curr->child[s[position]-'a'], position+1, n);
        }
        return 0;
    }
    WordDictionary() {
       
    }
    
    void addWord(string word) {
        insert_in_trie(word);
    }
    
    bool search(string word) {
        int n=word.size();
        return search_trie(word, root, 0, n);
        
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */