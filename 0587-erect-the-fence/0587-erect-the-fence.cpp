class Solution {
    int orientation(vector<int>a, vector<int>b, vector<int>c) {
        return (c[1]-b[1])*(b[0]-a[0]) - (b[1]-a[1])*(c[0] - b[0]);
    }    
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> hull(2*trees.size());
        int k = 0;
        
        for(int i = 0; i<trees.size(); i++) {
            while(k>=2 && orientation(hull[k-2], hull[k-1], trees[i]) > 0) 
                k--;
            hull[k++] = trees[i];
        }
        for(int i = trees.size() - 2; i>=0; i--) {
            while(k >= 2 && orientation(hull[k-2], hull[k-1], trees[i]) > 0)
                k--;
            hull[k++] = trees[i];
        }
        
        hull.resize(k);
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull; 
    }
};