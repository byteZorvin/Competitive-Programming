class UnionFind {
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int size) {
        parent = vector<int>(size);
        rank = vector<int>(size);
        for(int i = 0; i<size; ++i)
            parent[i] = i;
    }
    
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void join(int u, int v) {
        int x = findParent(u), y = findParent(v);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            parent[x] = y;
        }
        else if(rank[y] < rank[x]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        
        for(vector<int>&edge: pairs) {
            int source = edge[0], destination = edge[1];
            // join the characters into a component
            uf.join(source, destination);
        }
        
        unordered_map<int, vector<int>> parentTocomponent;
        // Get the indexes of the characters of the same component
        for(int vertex = 0; vertex < s.size(); vertex++) {
            int par = uf.findParent(vertex);
            parentTocomponent[par].push_back(vertex);
        }
        
        string ans(s.size(), ' ');
        for(auto component: parentTocomponent) {
            vector<char> characters;
            for(int index: component.second) {
                characters.push_back(s[index]);
            }
            
            //Sort the characters
            sort(characters.begin(), characters.end());
            for(int i = 0; i<characters.size(); i++) {
                ans[component.second[i]] = characters[i];
            }
        }
        return ans;
    }
};