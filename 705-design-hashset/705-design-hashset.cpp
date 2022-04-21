class MyHashSet {
public:
    vector<int> freq;
    MyHashSet() {
        freq = vector<int>(1e6+1);
    }
    
    void add(int key) {
        freq[key] = 1;
    }
    
    void remove(int key) {
        freq[key] = 0;
    }
    
    bool contains(int key) {
        return freq[key] != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */