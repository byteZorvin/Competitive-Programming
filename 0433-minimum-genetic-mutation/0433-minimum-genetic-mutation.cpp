class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = start.size(), mutation = 0;
        queue<string> q;
        unordered_set<string> seen;
        q.push(start);
        seen.insert(start);
        
        while(!q.empty()) {
            int nodesInQ = q.size();
            for(int x = 0; x<nodesInQ; x++) {
                string node = q.front();
                q.pop();
                if(node == end) return mutation;
                
                for(char c: "ACGT") {
                    for(int i = 0; i<n; i++) {
                        string neighbour = node;
                        if(neighbour[i] == c) continue;
                        neighbour[i] = c;
                        auto it = find(bank.begin(), bank.end(), neighbour);
                        if(seen.find(neighbour) == seen.end() && it != bank.end()) {
                            q.push(neighbour);
                            seen.insert(neighbour);
                        }
                    }
                }
            }
            mutation++;
        }
        return -1;
    }
};