class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m*n != r*c) return mat;
        vector<int> col;
        vector<vector<int>> ans;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                col.push_back(mat[i][j]);
                if(col.size() == c) ans.push_back(col), col.clear();
            }
        }
        return ans;
    }
};