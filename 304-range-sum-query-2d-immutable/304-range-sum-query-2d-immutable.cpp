class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix = matrix;
        for(int i = 1; i<m; i++) prefix[i][0] += prefix[i-1][0];
        for(int j = 1; j<n; j++) prefix[0][j] += prefix[0][j-1];
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2];
        
        if(col1>0) sum -= prefix[row2][col1-1];
        if(row1>0) sum -= prefix[row1-1][col2];
        if(col1>0 && row1>0) sum += prefix[row1-1][col1-1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */