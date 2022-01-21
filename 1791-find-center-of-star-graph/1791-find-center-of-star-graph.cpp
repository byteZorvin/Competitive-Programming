class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int node1 = edges[0][0], node2 = edges[0][1];
        if(edges[1][0] == node1) return node1;
        if(edges[1][0] == node2) return node2;
        return edges[1][1];
    }
};