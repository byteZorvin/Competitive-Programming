class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(101);
        row[0] = poured;
        for(int i = 1; i<=query_row; i++) {
            for(int j = i-1; j>=0; j--) {
                row[j+1] += row[j] = max(0.0, (row[j] - 1)/2);
            }
        }
        return min(row[query_glass], 1.0);
    }
};