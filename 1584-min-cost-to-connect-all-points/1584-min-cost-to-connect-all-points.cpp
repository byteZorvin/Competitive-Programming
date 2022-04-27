class UnionFind {
public:
    vector<int> rank;
    vector<int> parent;
    
    UnionFind(int size) {
        rank = vector<int>(size);
        parent = vector<int>(size);
        for(int i = 0; i<size; ++i) 
            parent[i] = i;
    }
    
    int findPar(int node) {
        if(parent[node] == node) 
            return node;
        return parent[node] = findPar(parent[node]);
    }
    
    bool join(int node1, int node2) {
        int x = findPar(node1), y = findPar(node2);
        if(x == y) return false;
        if(rank[x] > rank[y]) {
            parent[x] = y;
        }
        else if(rank[x] < rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            rank[y]++;
        } 
        return true;
    }
};

class Solution {
    struct Edge {
        int src, dest, weight;
        Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
    };
    
    static bool myCmp(Edge &e1, Edge &e2) {
        return e1.weight < e2.weight;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> allEdges;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int wt = abs(points[i][0] - points[j][0]) + 
                             abs(points[i][1] - points[j][1]);
                allEdges.push_back(Edge(i, j, wt));
            }
        }
        
        // Sort all Edges on the basis of their weights.
        sort(allEdges.begin(), allEdges.end(), myCmp);
        
        UnionFind uf(n);
        int mstCost = 0;
        
        for(int i = 0, size = 0; size<n-1, i<allEdges.size(); i++) {
            Edge e = allEdges[i];
            int u = e.src, v = e.dest;
            if(uf.join(u, v)) {
                mstCost += e.weight;
                size++;
            }
        }
        
        return mstCost;
    }
};