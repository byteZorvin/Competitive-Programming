class Solution {
    bool visited[100010] = {0};
    vector<int>adj[100010];
    void DFS(int v, string&s, vector<char> &ch, vector<int> &ind) {
        visited[v] = true;
        ind.push_back(v);
        ch.push_back(s[v]);
        
        for(int &neigh: adj[v]) {
            if(!visited[neigh]) 
                DFS(neigh, s, ch, ind);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        // Build adjacency list/Graph
        for(vector<int>&edge: pairs) {
            int source = edge[0], destination = edge[1];
            //Undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }
        
        for(int vertex = 0; vertex<s.size(); vertex++) {
            if(!visited[vertex]) {
                vector<char> characters;
                vector<int> indices;
                
                DFS(vertex, s, characters, indices);
                
                // Sort both the vectors and build the part string
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());
                
                for(int index = 0; index < indices.size(); index++) {
                    s[indices[index]] = characters[index];
                }
            }
        }
        return s;
    }
};