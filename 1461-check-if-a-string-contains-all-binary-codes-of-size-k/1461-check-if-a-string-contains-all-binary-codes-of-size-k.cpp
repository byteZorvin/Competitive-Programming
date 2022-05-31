class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n<(1<<k)+k-1) return false;
        
        int found = 0;
        vector<bool> visited(1<<k, false);
    
        for(int i = 0; i<n-k+1; i++) {
            int curr = stoi(s.substr(i, k), nullptr, 2);
            if(visited[curr] == false)
                found++, visited[curr] = true;
        }
        return found ==  1<<k;
    }
};