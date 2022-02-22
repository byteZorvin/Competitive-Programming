class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = -1;
        int l = 0, h = m-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target) h = mid-1;
            else {
                row = mid;
                l = mid+1;
            }
        }
        if(row == -1) return false;
        l = 0, h = n-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) h = mid-1;
            else 
                l = mid+1;
        }
        return false;
    }
};